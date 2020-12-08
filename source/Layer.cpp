#include "LearNN/Layer.h"
#include "LearNN/Exception.h"

namespace LearNN {

	const std::string Layer::GetType() {
		return type;
	}

	const Output& Layer::GetOutput() const {
		return (output);
	}

	const int Layer::GetOutputSize() const {
		return (outputSize);
	}


	const bool Layer::CheckSetup() const {
		return true;
	}

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

	std::string Layer::toString() const {
		std::string description = "Missing description";
		return description;
	}

}