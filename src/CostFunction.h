/*
 * Author: Vyn
 * Created: 2020-07-21 12:40
 * Modified: 2020-07-27 11:25
 */

#pragma once
#include "Vector.h"

namespace LearNN {
	
	class CostFunction {

		public:
		
		virtual double Calculate(OutputVector output, OutputVector expectedOutput) = 0;
		virtual double CalculateDerivative(OutputVector output, OutputVector expectedOutput, int withRespectToIndex) = 0;
	};
}