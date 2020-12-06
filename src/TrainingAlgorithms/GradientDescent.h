#pragma once

namespace LearNN {

    class NeuralNetwork;

	template<class CostFunction>
	class GradientDescent {

		public:

		void LearningStep(NeuralNetwork& neuralNet, const Input& input, const Output& expectedOutput);
        void Train(NeuralNetwork& neuralNet, std::vector<Input> inputs, std::vector<Output> expectedOutputs);
	};
}

#include "GradientDescent.tpp"