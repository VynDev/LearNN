#include "LearNN/Load.h"
#include "json-parser/JSON.h"

namespace LearNN {

    bool LoadNeuralNetwork(const std::string& filename, NeuralNetwork* neuralNet) {
        JSON::Object json(filename);
        if (!json.IsValid()) {
            return false;
        }
        neuralNet->SetInputSize(json["inputSize"].AsNumber());
        for (auto& element : json["layers"].AsArray().GetElements()) {
            auto& layerJson = element.get()->AsObject();

            auto* currentLayer = neuralNet->AddDenseLayer<Sigmoid>(layerJson["size"].AsNumber());

            auto& weights = currentLayer->GetWeightsPointer();

            for (int i = 0; i < layerJson["weights"].AsArray().GetElements().size(); ++i) {
                auto& weightJson = layerJson["weights"].AsArray().GetElements()[i];
                weights[i] = weightJson.get()->AsNumber();
            }
        }
        return false;
    }
}