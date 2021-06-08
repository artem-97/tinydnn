#pragma once

#include <cassert>
#include <climits>
#include <fstream>
#include <iostream>
#include <vector>

class Dataset {
 public:
  Dataset(const char* path);
  std::size_t size() const;
  std::vector<std::vector<int>> train();
  std::vector<int> test();
};

class MNIST : public Dataset {
 public:
  MNIST(const char*);
};
