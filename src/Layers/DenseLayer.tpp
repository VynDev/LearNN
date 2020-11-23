/*
 * Author: Vyn
 * Created: 2020-07-21 02:55
 * Modified: 2020-07-29 12:49
 */

#include "DenseLayer.h"
#include "../ActivationFunction.h"
#include "../ActivationFunctions/Sigmoid.h"
#include <cmath>

namespace LearNN {

	template <class ActivationFunctionClass>
	DenseLayer<ActivationFunctionClass>::DenseLayer(int neuronCount) {
		this->outputSize = neuronCount;
		this->neuronCount = neuronCount;
		this->biasCount = 1;
		this->activationFunction = new ActivationFunctionClass;

		this->activationFunction->Calculate(42);
	}
	
	template <class ActivationFunctionClass>
	const bool DenseLayer<ActivationFunctionClass>::Setup(const int inputSize) {
		this->inputSize = inputSize;

		weights.Clear();
		for (int weightIndex = 0; weightIndex < outputSize * (inputSize + 1); ++weightIndex) {
			weights.push_back((((2 * (double)rand()) / (double)RAND_MAX) - 1) * sqrt((double)1 / (double)inputSize));
		}
		return true;
	}

	template <class ActivationFunctionClass>
	const OutputVector& DenseLayer<ActivationFunctionClass>::CalculateOutput(const InputVector& input) {
		rawOutput.Clear();
		output.Clear();

		for (int outputIndex = 0; outputIndex < outputSize; ++outputIndex) {

			double raw = 0;
			for (int inputIndex = 0; inputIndex < inputSize; ++inputIndex) {
				raw += input[inputIndex] * GetWeight(outputIndex, inputIndex);
			}
			raw += 1 * GetWeight(outputIndex, inputSize); // Bias
			rawOutput.PushBack(raw);
			double neuronValue = activationFunction->Calculate(raw);
			output.PushBack(neuronValue);
		}

		return (output);
	}

	template <class ActivationFunctionClass>
	const NumericalVector DenseLayer<ActivationFunctionClass>::CalculateWeightsGradient(const NumericalVector& input, const NumericalVector& derivedValues) {
		NumericalVector gradients;

		for (int i = 0; i < output.Size(); ++i) {

			for (int j = 0; j < input.Size(); ++j) {
				double value = derivedValues[i] * activationFunction->CalculateDerivative(rawOutput[i]) * input[j];
				gradients.PushBack(value);
			}
			double value = derivedValues[i] * activationFunction->CalculateDerivative(rawOutput[i]) * 1; // bias
			gradients.PushBack(value);
			
		}

		return gradients;
	}

	template <class ActivationFunctionClass>
	const NumericalVector DenseLayer<ActivationFunctionClass>::CalculateDerivativeDependencies(const NumericalVector& input, const NumericalVector& derivedValues) {
		NumericalVector derivatives(input.Size(), 0);

		for (int i = 0; i < input.Size(); ++i) {
			for (int j = 0; j < output.size(); ++j) {
				derivatives[i] += derivedValues[j] * activationFunction->CalculateDerivative(rawOutput[j]) * GetWeight(j, i);
			}
		}

		return derivatives;
	}

	template <class ActivationFunctionClass>
	std::string DenseLayer<ActivationFunctionClass>::toString() const {
		std::string description = "Neuron count: " + std::to_string(neuronCount) + ", weight per neuron " + std::to_string(weights.Size() / neuronCount);
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