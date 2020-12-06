#pragma once
#include <vector>
#include <memory>
#include "Logger.h"
#include "Layers/DenseLayer.h"

namespace LearNN {

	class NeuralNetwork {

		public:
		
		NeuralNetwork(int inputSize);

		/**
		 *	Use this function to get a VECTOR of POINTERS to LAYERS, it's a direct access, not a copy.
		 *	@return The vector that contains all the layers.
		 */
		std::vector<std::unique_ptr<Layer>> &GetLayersPointer();

		/**
		 *	Returns a pointer to the last layer.
		 *	@return The pointer to the last layer or nullptr if there is no layer.
		 */
		Layer *GetLastLayer() const;

		/** 
		 * 	Add a dense layer to the end of the neural network, it's basically an helper function for AddLayer.  
		 *	You need to specify the activation function of the neurons as the first template parameter.  
		 *	@param neuronCount The number of neuron in this layer.
		 */
		template<class ActivationFunction>
		void AddDenseLayer(int neuronCount);

		/** 
		 * 	Train the neural network.  
		 *	You need to specify the training algorithm as the first template parameter.  
		 *	You need to specify the cost function as the second template parameter.
		 *	@param inputs The inputs to train on.
		 *	@param expectedOutputs The expectedOutput with respect to the inputs
		 */
		template<class TrainingMethod>
		void Train(const std::vector<Input> &inputs, const std::vector<Output> &expectedOutputs);

		/** 
		 * 	Given an input, calculate the output.    
		 *	@param inputs The inputs to train on.
		 *	@return A vector as the output.
		*/
		const Output &CalculateOutput(const Input& input);

		void Describe() const;

		private:

		void AddLayer(std::unique_ptr<Layer> layer);

		int inputSize;
		Input input;
		std::vector<std::unique_ptr<Layer>> layers;
	};
}

#include "NeuralNetwork.tpp"