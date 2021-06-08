#pragma once

#include <cassert>
#include <functional>
#include <tuple>
#include <vector>

#include "loss_fn.h"

class Loss {
 public:
  Loss(std::function<float(float, float)> f,
       std::function<float(float, float)>
           df);  // f -- loss function, df --it's derrivative

 protected:
  std::function<float(float, float)> f_;
  std::function<float(float, float)> df_;
};

class Logloss : public Loss {
 public:
  Logloss();
  auto operator()(std::vector<float> y_hat, std::vector<float> y)
      const;  // returns loss and gradient for y_hat
};

class CE_Loss : public Loss {
 public:
  CE_Loss(std::function<float(float)> f, std::function<float(float)> df);
  auto operator()(std::vector<std::vector<float>> y_hat,
                  std::vector<std::vector<float>> y)
      const;  // returns loss and gradient for y_hat
  CE_Loss();
};
