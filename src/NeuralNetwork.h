/*
 * Author: Vyn
 * Created: 2020-07-21 12:40
 * Modified: 2020-07-28 04:22
 */

#pragma once
#include <vector>
#include "Logger.h"
#include "Layers/DenseLayer.h"

namespace LearNN {

	class CostFunction;
	class Layer;

	class NeuralNetwork {

		public:
		
		NeuralNetwork(int inputSize);
		NeuralNetwork(NeuralNetwork &neuralNet);

		/**
		 *	Use this function to get a VECTOR of POINTERS to LAYERS, it's a direct access, not a copy.
		 *	@return The vector that contains all the layers.
		*/
		Vector<Layer *>& GetLayersPointer();

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
		template<class TrainingMethod, class CostFunction>
		void Train(const Vector<InputVector> &inputs, const Vector<InputVector> &expectedOutputs);

		/** 
		 * 	Given an input, calculate the output.    
		 *	@param inputs The inputs to train on.
		 *	@return A vector as the output.
		*/
		const OutputVector& CalculateOutput(const InputVector& input);

		void Describe() const;

		private:

		void AddLayer(Layer *layer);

		int inputSize;
		InputVector input;

		Vector<Layer *> layers;
	};
}

#include "NeuralNetwork.tpp"