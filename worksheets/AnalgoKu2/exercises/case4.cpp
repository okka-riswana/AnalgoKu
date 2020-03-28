#include "common/parser.h"
#include <algorithm> // std::copy
#include <chrono>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

/**
 * Study Case 4: Insertion Sort
 */
std::vector<uint64_t> caseAlgorithm(std::vector<uint64_t> data) {
  size_t i, j, imaks;
  uint64_t temp;

  for (i = data.size(); i > 1; --i) {
    imaks = 1;
    for (j = 1; j <= i; ++j) {
      if (data[j] > data[imaks]) {
        imaks = j;
      }
    }
    temp = data[i];
    data[i] = data[imaks];
    data[imaks] = temp;
  }

  return data;
}

int main(int argc, char const *argv[]) {
  if (argc != 3) {
    std::cerr << "usage: " << argv[0] << " <testfile> <out file>" << '\n';
    return EXIT_FAILURE;
  }

  // input data setup
  const std::string filename = argv[1];
  const std::string outfile = argv[2];
  std::ofstream out(outfile);
  std::vector<uint64_t> data = parseArray<uint64_t>(filename);

  if (data.empty()) {
    std::cerr << "Error: Input file is empty" << '\n';
    return EXIT_FAILURE;
  }

  auto start = std::chrono::high_resolution_clock::now();
  auto result = caseAlgorithm(data);
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;

  std::copy(result.begin(), result.end(),
            std::ostream_iterator<uint64_t>(out, "\n"));
  std::cout
      << "Result: " << outfile << "\n"
      << "Elapsed: "
      << std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count()
      << " milliseconds\n";

  return EXIT_SUCCESS;
}