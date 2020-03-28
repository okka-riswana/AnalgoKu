#include "common/parser.h"
#include <chrono>
#include <iostream>
#include <vector>

/**
 * Study Case 2: Sequential search
 */
size_t caseAlgorithm(const std::vector<uint64_t> &data,
                     const uint64_t &target) {
  size_t i = 0, idx;
  bool found = false;

  while (i < data.size() && !found) {
    if (data[i] == target) {
      found = true;
    } else {
      i = i + 1;
    }
  }

  if (found) {
    idx = i;
  } else {
    idx = -1;
  }

  return idx;
}

int main(int argc, char const *argv[]) {
  if (argc != 3) {
    std::cerr << "usage: " << argv[0] << " <testfile> <target int>" << '\n';
    return EXIT_FAILURE;
  }

  // input data setup
  std::string filename = argv[1];
  uint64_t target = std::strtoull(argv[2], NULL, 0);
  std::vector<uint64_t> data = parseArray<uint64_t>(filename);

  if (data.empty()) {
    std::cerr << "Error: Input file is empty" << '\n';
    return EXIT_FAILURE;
  }

  auto start = std::chrono::high_resolution_clock::now();
  auto result = caseAlgorithm(data, target);
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;

  std::cout
      << "Result:\n"
      << result << "\n"
      << "Elapsed: "
      << std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count()
      << " milliseconds\n";

  return EXIT_SUCCESS;
}