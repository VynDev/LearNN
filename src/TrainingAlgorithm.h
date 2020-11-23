/*
 * Author: Vyn
 * Created: 2020-07-21 12:40
 * Modified: 2020-07-28 04:22
 */

#pragma once
#include "Layer.h"

namespace LearNN {

    class NeuralNetwork;
	class CostFunction;

	class TrainingAlgorithm {

		public:

		TrainingAlgorithm() {}

        virtual void Train(NeuralNetwork& neuralNet, Vector<NumericalVector> inputs, Vector<NumericalVector> expectedOutputs, CostFunction& costFunction) = 0;

	};
}