/*
 * Author: Vyn
 * Created: 2020-07-21 12:40
 * Modified: 2020-07-28 02:08
 */

#pragma once
#include "Logger.h"
#include "Vector.h"

namespace LearNN {
	
	class Layer {

		/*
		*	The following methods and properties are implemented in this mother Layer class and provide utility/helper functions.
		*	Some of them need to be overridden, look at the comments.
		*/

		// Setup

		protected:

		std::string type = "layer";

		public:

		virtual ~Layer() {};
		virtual const std::string GetType();
		virtual const bool CheckSetup() const;
		virtual const bool Setup(const int inputSize) = 0;

		// Output

		protected:

		int outputSize; // must be set in child class
		OutputVector output; // should be used for the output, some functions depend on it, like CalculateOutput and GetOutput

		public:

		virtual const OutputVector& GetOutput() const;
		virtual const int GetOutputSize() const;
		virtual const OutputVector& CalculateOutput(const InputVector& input) = 0;

		// Weights

		protected:

		NumericalVector weights;

		public:

		virtual NumericalVector& GetWeights();
		virtual NumericalVector& GetWeightsPointer();
		virtual void SetWeights(const NumericalVector &newWeights);
		virtual const NumericalVector CalculateWeightsGradient(const NumericalVector& input, const NumericalVector& derivedValues);
		virtual const NumericalVector CalculateDerivativeDependencies(const NumericalVector& input, const NumericalVector& derivedValues) = 0;

		// Utils

		virtual std::string toString() const;

	};

}