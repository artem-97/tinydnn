#pragma once

#include <coroutine>
#include <exception>

class Dataset {
 public:
  Dataset(std::string path, bool train);
};
