/*
 * Author: Vyn
 * Created: 2020-07-21 12:40
 * Modified: 2020-07-28 04:22
 */

#pragma once
#include "../TrainingAlgorithm.h"

namespace LearNN {

    class NeuralNetwork;

	class GradientDescent : public TrainingAlgorithm {

		public:

        virtual void Train(NeuralNetwork& neuralNet, Vector<NumericalVector> inputs, Vector<NumericalVector> expectedOutputs, CostFunction& costFunction);

		void LearningStep(NeuralNetwork& neuralNet, const InputVector& input, const OutputVector& expectedOutput, CostFunction& costFunction);
	};
}