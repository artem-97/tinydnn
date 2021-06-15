#pragma once

#include "dataset.h"

class MNIST : public Dataset {
 public:
  MNIST(std::string path, bool train);
  std::size_t size() const;
  std::tuple<const std::vector<int>&, const std::vector<int>&> operator[](
      std::size_t idx) const;

 private:
  std::vector<std::vector<int>> Xs_;
  std::vector<std::vector<int>> ys_;
};
