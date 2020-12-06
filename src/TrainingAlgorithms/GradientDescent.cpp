#include "GradientDescent.h"
#include "../NeuralNetwork.h"
#include "../Vector.h"
#include "../CostFunction.h"

LOGGER("GD")

namespace LearNN {

    void GradientDescent::Train(NeuralNetwork& neuralNet, Vector<NumericalVector> inputs, Vector<NumericalVector> expectedOutputs, CostFunction& costFunction) {
        for (int i = 0; i < 100000; i++) {

            const OutputVector& output = neuralNet.CalculateOutput(inputs[0]);
            //PrintSuccess() << output[0] << " (Error: " <<  costFunction.Calculate(output, expectedOutputs[0]) << ")" << std::endl;
            LearningStep(neuralNet, inputs[0], expectedOutputs[0], costFunction);

            const OutputVector& output2 = neuralNet.CalculateOutput(inputs[1]);
            //PrintSuccess() << output2[0] << " (Error: " <<  costFunction.Calculate(output2, expectedOutputs[1]) << ")" << std::endl;
            LearningStep(neuralNet, inputs[1], expectedOutputs[1], costFunction);

            const OutputVector& output3 = neuralNet.CalculateOutput(inputs[2]);
            //PrintSuccess() << output3[0] << " (Error: " <<  costFunction.Calculate(output3, expectedOutputs[2]) << ")" << std::endl;
            LearningStep(neuralNet, inputs[2], expectedOutputs[2], costFunction);

            const OutputVector& output4 = neuralNet.CalculateOutput(inputs[3]);
            //PrintSuccess() << output4[0] << " (Error: " <<  costFunction.Calculate(output4, expectedOutputs[3])  << ")" << std::endl;
            LearningStep(neuralNet, inputs[3], expectedOutputs[3], costFunction);
        }
    }

    void GradientDescent::LearningStep(NeuralNetwork& neuralNet, const InputVector& input, const OutputVector& expectedOutput, CostFunction& costFunction) {

		NumericalVector derivedValues;
        Vector<Layer *> &layers = neuralNet.GetLayersPointer();
		Layer *lastLayer = layers[layers.Size() - 1];

		for (int i = 0; i < lastLayer->GetOutputSize(); ++i) {
			double value = costFunction.CalculateDerivative(lastLayer->GetOutput(), expectedOutput, i);
			derivedValues.push_back(value);
		}

		Vector<NumericalVector> weightsGradients;


		for (int i = layers.Size() - 1; i >= 0; --i) {
			Layer *layer = layers[i];

			weightsGradients.push_back(layer->CalculateWeightsGradient(i == 0 ? input : layers[i - 1]->GetOutput(), derivedValues));
			derivedValues = layer->CalculateDerivativeDependencies(i == 0 ? input : layers[i - 1]->GetOutput(), derivedValues);

		}

		for (int i = layers.Size() - 1; i >= 0; --i) {
			Layer *layer = layers[i];
			NumericalVector& weights = layer->GetWeightsPointer();

			for (int j = 0; j < weights.Size(); ++j) {
				weights[j] -= weightsGradients[layers.Size() - i - 1][j] * 0.1;
			}
		}
	}
}