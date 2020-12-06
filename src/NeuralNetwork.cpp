/*
 * Author: Vyn
 * Created: 2020-07-24 06:06
 * Modified: 2020-07-28 06:07
 */
#include "NeuralNetwork.h"
#include "Layer.h"

LOGGER("NeuralNetwork")

namespace LearNN {

	NeuralNetwork::NeuralNetwork(int inputSize) : inputSize(inputSize) {
		static bool isSrandAlreadyCalled = false;
		if (!isSrandAlreadyCalled) {
			srand(time(NULL));
			isSrandAlreadyCalled = true;
		}
	}

	void NeuralNetwork::AddLayer(std::unique_ptr<Layer> layer) {
		layer->Setup(GetLastLayer() ? GetLastLayer()->GetOutputSize() : inputSize);

		if (!layer->CheckSetup()) {
			PrintSuccess() << "Layer CheckSetup failed (" << layer->GetType() << ")" << std::endl;
			return ;
		}
		
		layers.push_back(std::move(layer));
	}

	const Output& NeuralNetwork::CalculateOutput(const Input& input) {
		this->input = input;
		Output const *lastOutput = &input;
		for (int i = 0; i < layers.size(); ++i) {
			Layer& layer = *(layers[i]);
			lastOutput = &(layer.CalculateOutput(*lastOutput));
		}

		return (*lastOutput);
	}

	void NeuralNetwork::Describe() const {
		std::cout << "Input size: " << inputSize;
		std::cout << "\nOutput size: " << layers[layers.size() - 1]->GetOutputSize();
		std::cout << "\nLayer count: " << layers.size() << "\n";
		for (int i = 0; i < layers.size(); ++i) {
			if (i != 0)
				std::cout << "\n----\n";
			std::cout << layers[i]->toString();
		}
		std::cout << std::endl;
	}

	std::vector<std::unique_ptr<Layer>>& NeuralNetwork::GetLayersPointer() {
		return layers;
	}

	Layer *NeuralNetwork::GetLastLayer() const {
		return layers.size() > 0 ? layers[layers.size() - 1].get() : nullptr;
	}
}