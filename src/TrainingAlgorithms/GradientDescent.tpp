#include "GradientDescent.h"
#include "../NeuralNetwork.h"
#include "../Vector.h"

LOGGER("GD")

namespace LearNN {

	template <class CostFunction>
    void GradientDescent<CostFunction>::Train(NeuralNetwork& neuralNet, std::vector<Input> inputs, std::vector<Output> expectedOutputs) {
        for (int i = 0; i < 100000; i++) {

            const Output& output = neuralNet.CalculateOutput(inputs[0]);
            //PrintSuccess() << output[0] << " (Error: " <<  costFunction.Calculate(output, expectedOutputs[0]) << ")" << std::endl;
            LearningStep(neuralNet, inputs[0], expectedOutputs[0]);

            const Output& output2 = neuralNet.CalculateOutput(inputs[1]);
            //PrintSuccess() << output2[0] << " (Error: " <<  costFunction.Calculate(output2, expectedOutputs[1]) << ")" << std::endl;
            LearningStep(neuralNet, inputs[1], expectedOutputs[1]);

            const Output& output3 = neuralNet.CalculateOutput(inputs[2]);
            //PrintSuccess() << output3[0] << " (Error: " <<  costFunction.Calculate(output3, expectedOutputs[2]) << ")" << std::endl;
            LearningStep(neuralNet, inputs[2], expectedOutputs[2]);

            const Output& output4 = neuralNet.CalculateOutput(inputs[3]);
            //PrintSuccess() << output4[0] << " (Error: " <<  costFunction.Calculate(output4, expectedOutputs[3])  << ")" << std::endl;
            LearningStep(neuralNet, inputs[3], expectedOutputs[3]);
        }
    }

	template <class CostFunction>
    void GradientDescent<CostFunction>::LearningStep(NeuralNetwork& neuralNet, const Input& input, const Output& expectedOutput) {

		Weights derivedValues;
        auto &layers = neuralNet.GetLayersPointer();
		Layer *lastLayer = layers[layers.size() - 1].get();

		for (int i = 0; i < lastLayer->GetOutputSize(); ++i) {
			double value = CostFunction::CalculateDerivative(lastLayer->GetOutput(), expectedOutput, i);
			derivedValues.push_back(value);
		}

		std::vector<Weights> weightsGradients;


		for (int i = layers.size() - 1; i >= 0; --i) {
			Layer *layer = layers[i].get();

			weightsGradients.push_back(layer->CalculateWeightsGradient(i == 0 ? input : layers[i - 1]->GetOutput(), derivedValues));
			derivedValues = layer->CalculateDerivativeDependencies(i == 0 ? input : layers[i - 1]->GetOutput(), derivedValues);

		}

		for (int i = layers.size() - 1; i >= 0; --i) {
			Layer *layer = layers[i].get();
			Weights& weights = layer->GetWeightsPointer();

			for (int j = 0; j < weights.size(); ++j) {
				weights[j] -= weightsGradients[layers.size() - i - 1][j] * 0.1;
			}
		}
	}
}