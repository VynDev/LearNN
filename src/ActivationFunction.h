/*
 * Author: Vyn
 * Created: 2020-07-21 12:40
 * Modified: 2020-07-27 11:25
 */

#pragma once

namespace LearNN {
	
	class ActivationFunction {

		public:
		
		virtual const double Calculate(double x) const = 0;
		virtual const double CalculateDerivative(double x) const = 0;
		virtual ~ActivationFunction() {};
	};
}