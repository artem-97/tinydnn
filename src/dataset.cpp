#include "dataset.h"

Dataset::Dataset(std::string path, bool train) {}

// Utility function for MNIST idx file format processing
template <typename T>
T swap_endian(T t) {
  static_assert(CHAR_BIT == 8, "CHAR_BIT != 8");

  union {
    T t;
    unsigned char u8[sizeof(T)];
  } source, dest;

  source.t = t;

  for (size_t k = 0; k < sizeof(T); k++)
    dest.u8[k] = source.u8[sizeof(T) - k - 1];

  return dest.t;
}

MNIST::MNIST(std::string path, bool train) : Dataset(path, train) {
  // processing idx file format
  // see http://yann.lecun.com/exdb/mnist/
  constexpr char idx_offset = 4;

  auto X_filename = train ? std::string("train-images-idx3-ubyte")
                          : std::string("t10k-images-idx3-ubyte");
  auto y_filename = train ? std::string("train-labels-idx1-ubyte")
                          : std::string("t10k-labels-idx1-ubyte");

  std::ifstream X_file;
  X_file.open(path + X_filename,
              std::ios::in | std::ios::out | std::ios::binary);
  X_file.seekg(idx_offset);

  std::ifstream y_file;
  y_file.open(path + y_filename,
              std::ios::in | std::ios::out | std::ios::binary);
  y_file.seekg(idx_offset);

  uint32_t X_size;
  uint32_t y_size;

  X_file.read((char*)&X_size, sizeof(X_size));
  X_size = swap_endian<uint32_t>(X_size);

  y_file.read((char*)&y_size, sizeof(y_size));
  y_size = swap_endian<uint32_t>(y_size);

  assert(X_size == y_size);

  uint32_t n_rows;
  X_file.read((char*)&n_rows, sizeof(X_size));
  n_rows = swap_endian<uint32_t>(n_rows);

  uint32_t n_cols;
  X_file.read((char*)&n_cols, sizeof(X_size));
  n_cols = swap_endian<uint32_t>(n_cols);

  // std::cout << n_rows << ":" << n_cols << '\n';
  std::vector<char> images((std::istreambuf_iterator<char>(X_file)),
                           std::istreambuf_iterator<char>());

  std::vector<char> labels((std::istreambuf_iterator<char>(y_file)),
                           std::istreambuf_iterator<char>());

  for (int i = 0; i < X_size; i++) {
    std::vector<int> x;
    for (int j = 0; j < n_cols * n_rows; j++) {
      auto idx = i * n_cols * n_rows + j;
      x.emplace_back(swap_endian<uint8_t>(static_cast<uint8_t>(images[idx])));
    }
    Xs_.emplace_back(x);
    auto digit = swap_endian<char>(static_cast<char>(labels[i]));
    auto y = std::vector<int>(10, 0);
    y[digit] = 1;
    ys_.emplace_back(y);
  }
}

std::size_t MNIST::size() const { return Xs_.size(); }

std::tuple<const std::vector<int>&, const std::vector<int>&> MNIST::operator[](
    std::size_t idx) const {
  return {Xs_[idx], ys_[idx]};
}