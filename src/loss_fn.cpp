#include "loss_fn.h"

float logloss(float y_hat, float y) {
  return -y * log(y_hat) - (1 - y) * log(1 - y_hat);
}

float dlogloss(float y_hat, float y) {
  return -y / y_hat + (1 - y) / (1 - y_hat);
}