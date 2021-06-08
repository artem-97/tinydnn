#include "dnn.h"

DNN::DNN() {}

void DNN::add_layer(const Layer& layer) { layers_.emplace_back(layer); }