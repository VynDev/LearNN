This is a neural network library made in C++, i created it to learn about neural networks and data science so it may contains errors and/or not being compatible with you OS/Version

## Quick examples

### Solving XOR gate

Create a file **main.cpp**

```cpp
/* main.cpp */
#include <iostream>
#include "LearNN/LearnNN.h"

using namespace std;
using namespace LearNN;

int main()
{
    NeuralNetwork neuralNet(2); // Create a neural network with input of size 2.

    /* Create 2 dense layers with 2 and 1 neurons, using the sigmoid function. */
    neuralNet.AddDenseLayer<Sigmoid>(2);
    neuralNet.AddDenseLayer<Sigmoid>(1);

    /* Define the inputs and the outputs for the XOR gate. */
    const vector<Input> inputs =           {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    const vector<Output> expectedOutputs = {{0},	{1},    {1},	{0}};

    /* 
    *  Train the neural network with the gradient descent method,
    *  using the mean squared error cost function.
    */
    neuralNet.Train<GradientDescent<MeanSquaredError>>(inputs, expectedOutputs);

    /* Show the results of the traning */
    cout << "0, 0: " << neuralNet.CalculateOutput(inputs[0])[0] << endl;
    cout << "0, 1: " << neuralNet.CalculateOutput(inputs[1])[0] << endl;
    cout << "1, 0: " << neuralNet.CalculateOutput(inputs[2])[0] << endl;
    cout << "1, 1: " << neuralNet.CalculateOutput(inputs[3])[0] << endl;

    /* Save the neural network structure in a json format */
    neuralNet.Save("xor.json");

    return 0;
}
```
To compile and execute this code:  
```
g++ -I path_to_LearNN/include -L path_to_LearNN/bin -L path_to_LearNN/libs/json-parser/bin main.cpp -o xor -lLearNN -ljson-parser
./xor
```

## Installation

### Requirements

- git
- g++ (developed with g++ (GCC) 10.2.0 on Arch Linux)
- premake5
- make

### Steps (Linux)

```
premake5 gmake
make
```

## Examples of projects using LearNN

### CarGenAI (using a old version of this lib)
Cars learning to drive in Unreal Engine 4 using genetic algorithm  
Demo: https://youtu.be/aslTSS2VpCA  
Github: https://github.com/VynDev/CarGenAI

### Kaggle's Titanic challenge (using a old version of this lib)
Challenge overview: https://www.kaggle.com/c/titanic/overview  
Github: https://github.com/VynDev/Kaggle-Titanic

## Documentation

There is no html documentation available at the moment because the lib is still experimental/in development and 
it's a personal project, you still have the documentation as comments into the headers.

## License

LGPLv3 (see the file "LICENSE" at the root)