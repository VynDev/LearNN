#pragma once
#include <cmath>

namespace LearNN {

	class Sigmoid {

		public:

		static const double Calculate(double x) {
			return (1 / (1 + (exp(-x))));
		}

		static const double CalculateDerivative(double x) {
			double value = Calculate(x);
			return (value * (1 - value));
		}
	};
}