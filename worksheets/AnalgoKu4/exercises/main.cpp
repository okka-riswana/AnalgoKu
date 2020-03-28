#include "data_source.hpp"
#include "option.hpp"
#include "sorting.hpp"
#include <algorithm>
#include <chrono>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>

static void show_usage(const std::string &program_name) {
  std::cerr
      << "Usage: " << program_name << " <option(s)>\n"
      << "Options:\n"
      << "\t-h"
      << "\t\tShow this help message.\n"
      << "\t-q"
      << "\t\tMuffle console output.\n"
      << "\t-a [m,s,i,b]"
      << "\tSorting algorithm. [m]erge, [s]election, [i]nsertion, [b]ubble.\n"
      << "\t-g NUMBER"
      << "\tGenerate NUMBER sized data. Default = 100.\n"
      << "\t-i FILE"
      << "\t\tInput file.\n"
      << "\t-o FILE"
      << "\t\tOutput file.\n";
}

int main(const int argc, const char **argv) {
  Analgo::InputParser input(argc, argv);

  if (input.option_exists("-h") || !input.option_exists("-a")) {
    show_usage(argv[0]);
    return EXIT_FAILURE;
  }

  const std::string &algorithm = input.get_option("-a");

  const std::string &input_file = input.get_option("-i");
  const bool input_flag = !input_file.empty();

  const std::string &output_file = input.get_option("-o");
  const bool output_flag = !output_file.empty();

  const std::string &generate = input.get_option("-g");
  const size_t gen_size = std::stoul(!generate.empty() ? generate : "100");

  const bool quiet_flag = input.option_exists("-q");

  std::vector<uint64_t> data =
      input_flag ? Analgo::parse_from_file<uint64_t>(input_file)
                 : Analgo::generate_random_uint(gen_size);

  if (data.empty()) {
    std::cerr << "Error: Input data is empty" << '\n';
    return EXIT_FAILURE;
  }

  std::ofstream outfile(output_file);
  std::ostream_iterator<uint64_t> output_stream(
      output_flag ? outfile : std::cout, "\n");

  std::function<void(std::vector<uint64_t>::iterator,
                     std::vector<uint64_t>::iterator)>
      sort_func;
  if (algorithm == "m") {
    sort_func = Analgo::Sorting::merge_sort<std::vector<uint64_t>::iterator>;
  } else if (algorithm == "i") {
    sort_func = Analgo::Sorting::recursive_insertion_sort<
        std::vector<uint64_t>::iterator>;
  } else if (algorithm == "b") {
    sort_func =
        Analgo::Sorting::recursive_bubble_sort<std::vector<uint64_t>::iterator>;
  } else if (algorithm == "s") {
    sort_func = Analgo::Sorting::recursive_selection_sort<
        std::vector<uint64_t>::iterator>;
  } else {
    show_usage(argv[0]);
    return EXIT_FAILURE;
  }

  auto start = std::chrono::high_resolution_clock::now();
  sort_func(data.begin(), data.end());
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;

  if (output_flag || !quiet_flag) {
    std::copy(data.begin(), data.end(), output_stream);
    std::cout << "\n";
  }

  std::cout
      << "Data Size: " << data.size() << "\n"
      << "Result: "
      << (output_flag ? output_file
                      : std::is_sorted(data.begin(), data.end()) ? "Sorted"
                                                                 : "Not Sorted")
      << "\n"
      << "Elapsed: "
      << std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count()
      << " nanoseconds\n";

  return EXIT_SUCCESS;
}