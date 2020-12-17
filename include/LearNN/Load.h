#pragma once
#include <string>
#include "NeuralNetwork.h"

namespace LearNN {

    bool LoadNeuralNetwork(const std::string& filename, NeuralNetwork* neuralNet);

}