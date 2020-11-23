/*
 * Author: Vyn
 * Created: 2020-07-21 12:40
 * Modified: 2020-07-27 11:25
 */

#pragma once
#include "../CostFunction.h"
#include "../Vector.h"
#include <cmath>

namespace LearNN {
	
	class MeanSquaredError : public CostFunction {

		public:

		MeanSquaredError() {};

		virtual double Calculate(OutputVector output, OutputVector expectedOutput) {
			double total = 0;

			for (int i = 0; i < output.Size(); ++i)
				total += std::pow(output[i] - expectedOutput[i], 2);
				
			return (total / output.Size());
		}

		virtual double CalculateDerivative(OutputVector output, OutputVector expectedOutput, int withRespectToIndex) {
			return (1 * (output[withRespectToIndex] - expectedOutput[withRespectToIndex]) / output.Size());
		}

	};
}