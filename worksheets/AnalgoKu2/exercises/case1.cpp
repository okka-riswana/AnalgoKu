#include "common/parser.h"
#include <chrono>
#include <iostream>
#include <vector>

/**
 * Study Case 1: Find max integer
 */
uint64_t caseAlgorithm(const std::vector<uint64_t> &data) {
  uint64_t maks = data[0];
  size_t i = 1;

  while (i < data.size()) {
    if (data[i] > maks) {
      maks = data[i];
    }
    i = i + 1;
  }

  return maks;
}

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    std::cerr << "usage: " << argv[0] << " <testfile>" << '\n';
    return EXIT_FAILURE;
  }

  // input data setup
  std::string filename = argv[1];
  std::vector<uint64_t> data = parseArray<uint64_t>(filename);

  if (data.empty()) {
    std::cerr << "Error: Input file is empty" << '\n';
    return EXIT_FAILURE;
  }

  auto start = std::chrono::high_resolution_clock::now();
  auto result = caseAlgorithm(data);
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
