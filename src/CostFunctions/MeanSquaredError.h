/*
 * Author: Vyn
 * Created: 2020-07-21 12:40
 * Modified: 2020-07-27 11:25
 */

#pragma once
#include "../Vector.h"
#include <cmath>

namespace LearNN {
	
	class MeanSquaredError {

		public:

		static double Calculate(Output output, Output expectedOutput) {
			double total = 0;

			for (int i = 0; i < output.size(); ++i)
				total += std::pow(output[i] - expectedOutput[i], 2);
				
			return (total / output.size());
		}

		static double CalculateDerivative(Output output, Output expectedOutput, int withRespectToIndex) {
			return (1 * (output[withRespectToIndex] - expectedOutput[withRespectToIndex]) / output.size());
		}

	};
}