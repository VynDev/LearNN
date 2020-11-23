/*
 * Author: Vyn
 * Created: 2020-07-24 06:06
 * Modified: 2020-07-28 06:07
 */
#include "NeuralNetwork.h"
#include "CostFunction.h"

LOGGER("NeuralNetwork")

namespace LearNN {

	NeuralNetwork::NeuralNetwork() {
		static bool isSrandAlreadyCalled = false;
		if (!isSrandAlreadyCalled) {
			srand(time(NULL));
			isSrandAlreadyCalled = true;
		}
	}

	NeuralNetwork::NeuralNetwork(NeuralNetwork &neuralNet) {
		*this = neuralNet;
	}


	void NeuralNetwork::SetInputSize(int size) {
		inputSize = size;
	}

	/* Layer */

	void NeuralNetwork::AddLayer(Layer *layer) {
		if (layers.Size() == 0)
			layer->Setup(inputSize);
		else
			layer->Setup(layers[layers.Size() - 1]->GetOutputSize());

		if (!layer->CheckSetup()) {
			PrintSuccess() << "Layer CheckSetup failed (" << layer->GetType() << ")" << std::endl;
			return ;
		}
		
		layers.push_back(layer);
		//PrintSuccess() << "Successfully added a layer (" << layer->GetType() << ")" << std::endl;
	}

	const OutputVector& NeuralNetwork::CalculateOutput(const InputVector& input) {
		this->input = input;
		OutputVector const *lastOutput = &input;
		for (int i = 0; i < layers.Size(); ++i) {
			Layer& layer = *(layers[i]);
			lastOutput = &(layer.CalculateOutput(*lastOutput));
		}

		return (*lastOutput);
	}

	void NeuralNetwork::Describe() const {
		std::cout << "Input size: " << inputSize;
		std::cout << "\nOutput size: " << layers[layers.Size() - 1]->GetOutputSize();
		std::cout << "\nLayer count: " << layers.Size() << "\n";
		for (int i = 0; i < layers.Size(); ++i) {
			if (i != 0)
				std::cout << "\n----\n";
			std::cout << layers[i]->toString();
		}
		std::cout << std::endl;
	}

	Vector<Layer *>& NeuralNetwork::GetLayersPointer() {
		return layers;
	}
}