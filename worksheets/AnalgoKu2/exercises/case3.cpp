#include "common/parser.h"
#include <algorithm> // std::sort
#include <chrono>
#include <iostream>
#include <vector>

/**
 * Study Case 3: Binary search
 */
size_t caseAlgorithm(const std::vector<uint64_t> &data,
                     const uint64_t &target) {
  size_t i = 0, j = data.size(), mid, idx;
  bool found = false;

  while (i <= j && !found) {
    mid = (i + j) / 2;
    if (data[mid] == target) {
      found = true;
    } else {
      if (data[mid] < target) {
        i = mid + 1;
      } else {
        j = mid - 1;
      }
    }
  }

  if (found) {
    idx = mid;
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

  // Sort the data for binary search
  std::sort(data.begin(), data.end());

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