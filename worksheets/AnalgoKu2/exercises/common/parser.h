#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <iterator>
#include <string>
#include <vector>

template <class T> std::vector<T> parseArray(std::string filename) {
  std::ifstream inputFile(filename);
  std::istream_iterator<T> start(inputFile), end;
  std::vector<T> inputArray(start, end);
  return inputArray;
}

#endif