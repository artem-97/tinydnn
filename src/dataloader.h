#pragma once

#include <tuple>
#include <vector>

#include "dataset.h"

class Dataloader {
 public:
  Dataloader(const Dataset&, int batch_size);

 private:
  const Dataset& dataset_;
  int batch_size_;
};