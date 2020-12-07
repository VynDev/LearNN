/*
 * Author: Vyn
 * Created: 2020-07-21 11:32
 * Modified: 2020-07-25 06:40
 */

#pragma once
#include "typedef.h"
#include "Logger.h"
#include "Exception.h"
#include "NeuralNetwork.h"

#include "Layer.h"
#include "Layers/DenseLayer.h"

#include "ActivationFunctions/Sigmoid.h"

#include "CostFunctions/MeanSquaredError.h"

#include "TrainingAlgorithms/GradientDescent.h"