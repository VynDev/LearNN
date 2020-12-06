#pragma once
#include "NeuralNetwork.h"

namespace LearNN {

    template<class T>
    void NeuralNetwork::AddDenseLayer(int neuronCount) {
        AddLayer(new DenseLayer<T>(neuronCount));
    }

    template<class TrainingMethod, class CostFunction>
    void NeuralNetwork::Train(const Vector<InputVector> &inputs, const Vector<InputVector> &expectedOutputs) {
        TrainingMethod trainingMethod;
        CostFunction costFunction;
        trainingMethod.Train(*this, inputs, expectedOutputs, costFunction);
    }

}