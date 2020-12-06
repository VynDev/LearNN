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

		/* Setup */

		protected:

		std::string type = "layer";

		public:

		virtual ~Layer() {};

		virtual const std::string GetType();
		virtual const bool CheckSetup() const;
		virtual const bool Setup(const int inputSize) = 0;

		/* Output */

		protected:

		int outputSize; // must be set in child class
		Output output; // should be used for the output, some functions depend on it, like CalculateOutput and GetOutput

		public:

		virtual const Output& GetOutput() const;
		virtual const int GetOutputSize() const;
		virtual const Output& CalculateOutput(const Input& input) = 0;

		/* Weights */

		protected:

		Weights weights;

		public:

		virtual Weights& GetWeights();
		virtual Weights& GetWeightsPointer();
		virtual void SetWeights(const Weights &newWeights);
		virtual const Weights CalculateWeightsGradient(const Input& input, const Output& derivedValues);
		virtual const Weights CalculateDerivativeDependencies(const Input& input, const Output& derivedValues) = 0;

		/* Utils */

		virtual std::string toString() const;

	};

}