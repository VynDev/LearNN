/*
 * Author: Vyn
 * Created: 2020-07-21 12:40
 * Modified: 2020-07-28 04:09
 */

#pragma once
#include "../Layer.h"

namespace LearNN {

	class ActivationFunction;
	
	template <class ActivationFunctionClass>
	class DenseLayer : public Layer {

		/* Setup */

		protected:

		std::string type = "dense";

		public:

		DenseLayer(int neuronCount);

		virtual const std::string GetType() {return type;};
		virtual const bool Setup(const int inputSize);
		virtual ~DenseLayer() {};

		/* Activation function */

		private:

		ActivationFunction *activationFunction = nullptr;

		/* Input */

		int inputSize;

		/* Output (Neuron) */

		private:

		NumericalVector rawOutput;
		int neuronCount;

		public:

		virtual const OutputVector& CalculateOutput(const InputVector& input);

		const double GetNeuronValue(int neuronIndex) const;
		const double GetRawNeuronValue(int neuronIndex) const;
		void SetNeuronValue(int neuronIndex, double newNeuronValue);
		void SetRawNeuronValue(int neuronIndex, double newRawNeuronValue);

		/* Weights */

		private:

		int biasCount;

		public:

		virtual const NumericalVector CalculateWeightsGradient(const NumericalVector& input, const NumericalVector& derivedValues);
		virtual const NumericalVector CalculateDerivativeDependencies(const NumericalVector& input, const NumericalVector& derivedValues);
		const double GetWeight(int neuronIndex, int weightIndex) const;
		void SetWeight(int neuronIndex, int weightIndex, double newWeightValue);

		/* Utils */

		private:

		public:

		virtual std::string toString() const;

	};
}

#include "DenseLayer.tpp"