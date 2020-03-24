#ifndef DATA_SOURCE_HPP
#define DATA_SOURCE_HPP

#include <algorithm>
#include <fstream>
#include <functional>
#include <iterator>
#include <random>
#include <string>
#include <vector>

namespace Analgo {

template <typename T>
std::vector<T> parse_from_file(const std::string &filename) {
  std::ifstream inputFile(filename);
  std::istream_iterator<T> start(inputFile), end;
  std::vector<T> data(start, end);
  return data;
}

std::vector<uint64_t> generate_random_uint(const size_t &size) {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<> dis(0, size);
  std::vector<uint64_t> data(size);
  std::generate(data.begin(), data.end(), std::bind(dis, std::ref(mt)));
  return data;
}

} // namespace Analgo

#endif