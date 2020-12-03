#include <iostream>
#include "../../src/LearnNN.h"

using namespace std;
using namespace LearNN;

LOGGER("Xor example")

int main()
{
	PrintDebug() << "Starting Xor example" << endl;

	NeuralNetwork neuralNet;
	MeanSquaredError meanSquaredError;

	neuralNet.SetInputSize(2);
	neuralNet.AddLayer(new DenseLayer<Sigmoid>(2)); 
	neuralNet.AddLayer(new DenseLayer<Sigmoid>(1));

	//neuralNet.AddDenseLayer<Sigmoid>(2); // <= expected form

	const Vector<InputVector> inputs =			{{0, 0}, {0, 1}, {1, 0}, {1, 1}};
	const Vector<InputVector> expectedOutputs = {{0},	 {1},    {1},	 {0}};

	GradientDescent gradientDescent;
	gradientDescent.Train(neuralNet, inputs, expectedOutputs, meanSquaredError);

	//neuralNet.Train<GradientDescent<MeanSquaredError>>(inputs, expectedOutputs); // <= expected form

    std::cout << neuralNet.CalculateOutput(inputs[0])[0] << std::endl;
    std::cout << neuralNet.CalculateOutput(inputs[1])[0] << std::endl;
    std::cout << neuralNet.CalculateOutput(inputs[2])[0] << std::endl;
    std::cout << neuralNet.CalculateOutput(inputs[3])[0] << std::endl;

}

// Expected form below

/*int main()
{
	NeuralNetwork neuralNet;

	neuralNet.AddDenseLayer<Sigmoid>(2); 
	neuralNet.AddDenseLayer<Sigmoid>(1);

	const Vector<InputVector> inputs =			{{0, 0}, {0, 1}, {1, 0}, {1, 1}};
	const Vector<InputVector> expectedOutputs = {{0},	 {1},    {1},	 {0}};

	neuralNet.Train<GradientDescent<MeanSquaredError>>(inputs, expectedOutputs); // <= expected form

    cout << neuralNet.CalculateOutput(inputs[0])[0] << endl;
    cout << neuralNet.CalculateOutput(inputs[1])[0] << endl;
    cout << neuralNet.CalculateOutput(inputs[2])[0] << endl;
    cout << neuralNet.CalculateOutput(inputs[3])[0] << endl;

}*/