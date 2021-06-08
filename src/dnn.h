#pragma once

#include <vector>

#include "layer.h"

class DNN {
 public:
  DNN();
  void add_layer(const Layer&);

 private:
  std::vector<Layer> layers_;
};