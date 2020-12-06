#include "Layer.h"
#include "Exception.h"

LOGGER("Layer")

namespace LearNN {

	// Type

	const std::string Layer::GetType() {
		return type;
	}

	// Output

	const Output&	Layer::GetOutput() const {
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

	Weights& Layer::GetWeights() {
		return weights;
	}

	Weights& Layer::GetWeightsPointer() {
		return weights;
	}

	void Layer::SetWeights(const Weights &newWeights) {
		weights = newWeights;
	}

	const Weights Layer::CalculateWeightsGradient(const Input& input, const Weights& derivedValues) {
		throw MissingImplementationException(GetType());
	}

	// Utils

	std::string Layer::toString() const {
		std::string description = "Missing description";
		return description;
	}

}