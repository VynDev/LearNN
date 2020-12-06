#include "DenseLayer.h"
#include "../ActivationFunctions/Sigmoid.h"
#include <cmath>

namespace LearNN {

	template <class ActivationFunctionClass>
	DenseLayer<ActivationFunctionClass>::DenseLayer(int neuronCount) {
		this->outputSize = neuronCount;
		this->neuronCount = neuronCount;
		this->biasCount = 1;
	}
	
	template <class ActivationFunctionClass>
	const bool DenseLayer<ActivationFunctionClass>::Setup(const int inputSize) {
		this->inputSize = inputSize;

		weights.clear();
		for (int weightIndex = 0; weightIndex < outputSize * (inputSize + 1); ++weightIndex) {
			weights.push_back((((2 * (double)rand()) / (double)RAND_MAX) - 1) * sqrt((double)1 / (double)inputSize));
		}
		return true;
	}

	template <class ActivationFunctionClass>
	const Output& DenseLayer<ActivationFunctionClass>::CalculateOutput(const Input& input) {
		rawOutput.clear();
		output.clear();

		for (int outputIndex = 0; outputIndex < outputSize; ++outputIndex) {

			double raw = 0;
			for (int inputIndex = 0; inputIndex < inputSize; ++inputIndex) {
				raw += input[inputIndex] * GetWeight(outputIndex, inputIndex);
			}
			raw += 1 * GetWeight(outputIndex, inputSize); // Bias
			rawOutput.push_back(raw);
			double neuronValue = ActivationFunctionClass::Calculate(raw);
			output.push_back(neuronValue);
		}

		return (output);
	}

	template <class ActivationFunctionClass>
	const Weights DenseLayer<ActivationFunctionClass>::CalculateWeightsGradient(const Input& input, const Weights& derivedValues) {
		Weights gradients;

		for (int i = 0; i < output.size(); ++i) {

			for (int j = 0; j < input.size(); ++j) {
				double value = derivedValues[i] * ActivationFunctionClass::CalculateDerivative(rawOutput[i]) * input[j];
				gradients.push_back(value);
			}
			double value = derivedValues[i] * ActivationFunctionClass::CalculateDerivative(rawOutput[i]) * 1; // bias
			gradients.push_back(value);
			
		}

		return gradients;
	}

	template <class ActivationFunctionClass>
	const Weights DenseLayer<ActivationFunctionClass>::CalculateDerivativeDependencies(const Input& input, const Weights& derivedValues) {
		Weights derivatives(input.size(), 0);

		for (int i = 0; i < input.size(); ++i) {
			for (int j = 0; j < output.size(); ++j) {
				derivatives[i] += derivedValues[j] * ActivationFunctionClass::CalculateDerivative(rawOutput[j]) * GetWeight(j, i);
			}
		}

		return derivatives;
	}

	template <class ActivationFunctionClass>
	std::string DenseLayer<ActivationFunctionClass>::toString() const {
		std::string description = "Neuron count: " + std::to_string(neuronCount) + ", weight per neuron " + std::to_string(weights.size() / neuronCount);
		return description;
	}

	template <class ActivationFunctionClass>
	const double DenseLayer<ActivationFunctionClass>::GetWeight(int neuronIndex, int weightIndex) const {
		return weights[neuronIndex * (inputSize + biasCount) + weightIndex];
	}

	template <class ActivationFunctionClass>
	void DenseLayer<ActivationFunctionClass>::SetWeight(int neuronIndex, int weightIndex, double newWeightValue) {
		weights[neuronIndex * (inputSize + biasCount) + weightIndex] = newWeightValue;
	}

	template <class ActivationFunctionClass>
	const double DenseLayer<ActivationFunctionClass>::GetNeuronValue(int neuronIndex) const {
		return output[neuronIndex];
	}

	template <class ActivationFunctionClass>
	const double DenseLayer<ActivationFunctionClass>::GetRawNeuronValue(int neuronIndex) const {
		return rawOutput[neuronIndex];
	}

	template <class ActivationFunctionClass>
	void DenseLayer<ActivationFunctionClass>::SetNeuronValue(int neuronIndex, double newNeuronValue) {
		output[neuronIndex] = newNeuronValue;
	}

	template <class ActivationFunctionClass>
	void DenseLayer<ActivationFunctionClass>::SetRawNeuronValue(int neuronIndex, double newRawNeuronValue) {
		rawOutput[neuronIndex] = newRawNeuronValue;
	}
}