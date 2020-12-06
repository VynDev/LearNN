#include <iostream>
#include <chrono>
#include "../../src/LearnNN.h"

using namespace std;
using namespace LearNN;

int main()
{
	NeuralNetwork neuralNet(2);

	neuralNet.AddDenseLayer<Sigmoid>(2);
	neuralNet.AddDenseLayer<Sigmoid>(1);

	const Vector<InputVector> inputs =			{{0, 0}, {0, 1}, {1, 0}, {1, 1}};
	const Vector<InputVector> expectedOutputs = {{0},	 {1},    {1},	 {0}};

	auto startTime = chrono::high_resolution_clock::now();
	neuralNet.Train<GradientDescent, MeanSquaredError>(inputs, expectedOutputs);
	auto endTime = chrono::high_resolution_clock::now();

	cout << "Training took " << (float)chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count() / 1000 << " second(s)." << endl;

    cout << "0, 0: " << neuralNet.CalculateOutput(inputs[0])[0] << endl;
    cout << "0, 1: " << neuralNet.CalculateOutput(inputs[1])[0] << endl;
    cout << "1, 0: " << neuralNet.CalculateOutput(inputs[2])[0] << endl;
    cout << "1, 1: " << neuralNet.CalculateOutput(inputs[3])[0] << endl;

	return 0;
}