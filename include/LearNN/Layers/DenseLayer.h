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

		/* Input */

		int inputSize;

		/* Output (Neuron) */

		private:

		Output rawOutput;
		int neuronCount;

		public:

		virtual const Output& CalculateOutput(const Input& input);

		const double GetNeuronValue(int neuronIndex) const;
		const double GetRawNeuronValue(int neuronIndex) const;
		void SetNeuronValue(int neuronIndex, double newNeuronValue);
		void SetRawNeuronValue(int neuronIndex, double newRawNeuronValue);

		/* Weights */

		private:

		int biasCount;

		public:

		virtual const Weights CalculateWeightsGradient(const Input& input, const Output& derivedValues);
		virtual const Weights CalculateDerivativeDependencies(const Input& input, const Output& derivedValues);
		const double GetWeight(int neuronIndex, int weightIndex) const;
		void SetWeight(int neuronIndex, int weightIndex, double newWeightValue);

		/* Utils */

		private:

		public:

		virtual std::string toString() const;

	};
}

#include "DenseLayer.tpp"