#pragma once
#include "NeuralNetwork.h"

namespace LearNN {

    template<class T>
    void NeuralNetwork::AddDenseLayer(int neuronCount) {
        AddLayer(std::make_unique<DenseLayer<T>>(neuronCount));
    }

    template<class TrainingMethod>
    void NeuralNetwork::Train(const std::vector<Input> &inputs, const std::vector<Output> &expectedOutputs) {
        TrainingMethod trainingMethod;
        trainingMethod.Train(*this, inputs, expectedOutputs);
    }
}