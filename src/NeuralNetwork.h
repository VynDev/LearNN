/*
 * Author: Vyn
 * Created: 2020-07-21 12:40
 * Modified: 2020-07-28 04:22
 */

#pragma once
#include <vector>
#include "Logger.h"
#include "Layer.h"

namespace LearNN {

	class CostFunction;

	class NeuralNetwork {

		public:

		NeuralNetwork();
		NeuralNetwork(NeuralNetwork &neuralNet);

		void SetInputSize(int size);

		/* Layer */

		void AddLayer(Layer *layer);
		Vector<Layer *>& GetLayersPointer();

		/* Neural Network */

		const OutputVector& CalculateOutput(const InputVector& input);

		/* Utils */

		void Describe() const;

		private:

		int inputSize;
		InputVector input;

		Vector<Layer *> layers;

	};
}