#include "dataset.h"

template <typename T>
T swap_endian(T u) {
  static_assert(CHAR_BIT == 8, "CHAR_BIT != 8");

  union {
    T u;
    unsigned char u8[sizeof(T)];
  } source, dest;

  source.u = u;

  for (size_t k = 0; k < sizeof(T); k++)
    dest.u8[k] = source.u8[sizeof(T) - k - 1];

  return dest.u;
}

Dataset::Dataset(const char* path) {}

MNIST::MNIST(const char* path) : Dataset(path) {
  constexpr char idx_offset = 4;

  std::ifstream X_train;
  X_train.open(
      "/home/artem/Prog/cpp/tinydnn/dataset/mnist/train/"
      "train-images-idx3-ubyte",
      std::ios::in | std::ios::out | std::ios::binary);
  X_train.seekg(idx_offset);

  std::ifstream y_train;
  y_train.open(
      "/home/artem/Prog/cpp/tinydnn/dataset/mnist/train/"
      "train-labels-idx1-ubyte",
      std::ios::in | std::ios::out | std::ios::binary);
  y_train.seekg(idx_offset);

  uint32_t X_train_size;
  uint32_t y_train_size;

  X_train.read((char*)&X_train_size, sizeof(X_train_size));
  X_train_size = swap_endian<uint32_t>(X_train_size);

  y_train.read((char*)&y_train_size, sizeof(y_train_size));
  y_train_size = swap_endian<uint32_t>(y_train_size);

  assert(X_train_size == y_train_size);

  uint32_t n_rows;
  X_train.read((char*)&n_rows, sizeof(X_train_size));
  n_rows = swap_endian<uint32_t>(n_rows);

  uint32_t n_cols;
  X_train.read((char*)&n_cols, sizeof(X_train_size));
  n_cols = swap_endian<uint32_t>(n_cols);

  std::cout << n_rows << ":" << n_cols << '\n';
  std::vector<char> images((std::istreambuf_iterator<char>(X_train)),
                           std::istreambuf_iterator<char>());
  std::vector<std::vector<int>> x_train;
  for (int i = 0; i < X_train_size; i++) {
    std::vector<int> img;
    for (int j = 0; j < n_cols * n_rows; j++) {
      auto idx = i * n_cols * n_rows + j;
      img.emplace_back(swap_endian<int>(static_cast<int>(images[idx])));
    }
    x_train.emplace_back(img);
  }

  std::vector<char> labels((std::istreambuf_iterator<char>(y_train)),
                           std::istreambuf_iterator<char>());
  std::cout << labels.size();
}