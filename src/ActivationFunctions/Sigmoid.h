/*
 * Author: Vyn
 * Created: 2020-07-21 12:40
 * Modified: 2020-07-27 11:25
 */

#pragma once
#include "../ActivationFunction.h"
#include "../Vector.h"
#include <cmath>

namespace LearNN {
	
	class Sigmoid : public ActivationFunction {

		public:

		Sigmoid() {};

		virtual const double Calculate(double x) const
		{
			return (1 / (1 + (exp(-x))));
		}

		virtual const double CalculateDerivative(double x) const
		{
			double value = Calculate(x);
			return (value * (1 - value));
		}

	};
}