#include "Layer.h"
#include "Exception.h"

LOGGER("Layer")

namespace LearNN {

	// Type

	const std::string Layer::GetType() {
		return type;
	}

	// Output

	const OutputVector&	Layer::GetOutput() const {
		return (output);
	}

	const int Layer::GetOutputSize() const {
		return (outputSize);
	}

	// Setup

	const bool Layer::CheckSetup() const {
		return true;
	}

	// Weights

	NumericalVector& Layer::GetWeights() {
		return weights;
	}

	NumericalVector& Layer::GetWeightsPointer() {
		return weights;
	}

	void Layer::SetWeights(const NumericalVector &newWeights) {
		weights = newWeights;
	}

	const NumericalVector Layer::CalculateWeightsGradient(const NumericalVector& input, const NumericalVector& derivedValues) {
		throw MissingImplementationException(GetType());
	}

	// Utils

	std::string Layer::toString() const {
		std::string description = "Missing description";
		return description;
	}

}