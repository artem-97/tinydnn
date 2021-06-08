#include "loss.h"

Loss::Loss(std::function<float(float, float)> f,
           std::function<float(float, float)> df)
    : f_(f), df_(df){};

// Logloss
Logloss::Logloss() : Loss(logloss, dlogloss){};

auto Logloss::operator()(std::vector<float> y_hat, std::vector<float> y) const {
  assert(y_hat.size() == y.size());
  auto loss = 0.;
  auto dloss = std::vector<float>(y.size());
  for (int i = 0; i < y.size(); i++) {
    loss += f_(y_hat[i], y[i]);
    dloss[i] = df_(y_hat[i], y[i]);
  }
}

// CE_Loss
CE_Loss::CE_Loss() : Loss(logloss, dlogloss){};

auto CE_Loss::operator()(std::vector<std::vector<float>> y_hat,
                         std::vector<std::vector<float>> y) const {}
