#include <ranges>
#include "GradientDescent.h"
#include "../NeuralNetwork.h"
#include "../typedef.h"

namespace LearNN {

	template <class CostFunction>
    void GradientDescent<CostFunction>::Train(NeuralNetwork& neuralNet, std::vector<Input> inputs, std::vector<Output> expectedOutputs) {
        for (int i = 0; i < 100000; i++) {
			for (int j = 0; j < inputs.size(); ++j) {
				neuralNet.CalculateOutput(inputs[j]); // The neural network needs to calculate the output first to be able to propagate the error.
				LearningStep(neuralNet, inputs[j], expectedOutputs[j]);
			}
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