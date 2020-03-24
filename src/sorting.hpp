#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP
#pragma once

#include <algorithm>
#include <functional>
#include <iterator>
#include <vector>

namespace Analgo {

namespace Sorting {

// merge_sort

/**
 * @brief Merge two sorted ranges.
 *
 * @param first1  An iterator
 * @param last1   Another iterator.
 * @param first2  Another iterator.
 * @param last2   Another iterator.
 * @param result  An iterator pointing to the end of the merged range.
 * @param comp    A functor to use for comparisons.
 * @return        An iterator pointing to the first element "not less
 *                than" @e val.
 */
template <typename InputIterator1, typename InputIterator2,
          typename OutputIterator, typename Compare>
OutputIterator merge(InputIterator1 first1, InputIterator1 last1,
                     InputIterator2 first2, InputIterator2 last2,
                     OutputIterator result, Compare comp) {
  for (; first1 != last1; ++result) {
    if (first2 == last2) {
      return std::copy(first1, last1, result);
    }
    if (comp(*first2, *first1)) {
      *result = *first2;
      ++first2;
    } else {
      *result = *first1;
      ++first1;
    }
  }
  return std::copy(first2, last2, result);
}

/**
 * @brief Merge sort implementation.
 *
 * @param first1  An iterator
 * @param last1   Another iterator.
 * @param first2  Another iterator.
 * @param last2   Another iterator.
 * @param comp    A functor to use for comparisons.
 * @return        Nothing.
 */
template <typename RandomAccessIterator1, typename RandomAccessIterator2,
          typename Compare>
void merge_sort(RandomAccessIterator1 first1, RandomAccessIterator1 last1,
                RandomAccessIterator2 first2, RandomAccessIterator2 last2,
                Compare comp) {
  const auto distance = std::distance(first1, last1);
  if (distance < 2) {
    return;
  }
  const auto middle1 = std::next(first1, distance >> 1);
  const auto middle2 = std::next(first2, distance >> 1);
  merge_sort(first2, middle2, first1, middle1, comp);
  merge_sort(middle2, last2, middle1, last1, comp);
  Sorting::merge(first2, middle2, middle2, last2, first1, comp); // ADL
}

/**
 * @brief Buffered merge sort implementation.
 *
 * @param first   An iterator
 * @param last    Another iterator.
 * @param comp    A functor to use for comparisons.
 * @return        Nothing.
 */
template <typename RandomAccessIterator, typename Compare>
void merge_sort(RandomAccessIterator first, RandomAccessIterator last,
                Compare comp) {
  const auto distance = std::distance(first, last);
  if (distance < 2) {
    return;
  }
  using value_type =
      typename std::iterator_traits<RandomAccessIterator>::value_type;
  std::vector<value_type> buffer(first, last);
  merge_sort(first, last, buffer.begin(), buffer.end(), comp);
}

/**
 * @brief Buffered merge sort implementation.
 *
 * @param first   An iterator
 * @param last    Another iterator.
 * @return        Nothing.
 */
template <typename RandomAccessIterator>
void merge_sort(RandomAccessIterator first, RandomAccessIterator last) {
  merge_sort(
      first, last,
      std::less<
          typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

// recursive_bubble_sort

/**
 * @brief Recursive bubble sort implementation.
 *
 * @param first   An iterator
 * @param last    Another iterator.
 * @param comp    A functor to use for comparisons.
 * @return        Nothing.
 */
template <typename RandomAccessIterator, typename Compare>
void recursive_bubble_sort(RandomAccessIterator first,
                           RandomAccessIterator last, Compare comp) {
  if (std::distance(first, last) > 1) {
    for (auto left = first, right = first + 1; right != last; ++left, ++right) {
      if (comp(*right, *left)) {
        std::iter_swap(left, right);
      }
    }
    recursive_bubble_sort(first, --last, comp);
  }
}

/**
 * @brief Recursive bubble sort implementation.
 *
 * @param first   An iterator
 * @param last    Another iterator.
 * @return        Nothing.
 */
template <typename RandomAccessIterator>
void recursive_bubble_sort(RandomAccessIterator first,
                           RandomAccessIterator last) {
  recursive_bubble_sort(
      first, last,
      std::less<
          typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

// recursive_insertion_sort

/**
 * @brief Recursive insertion sort implementation.
 *
 * @param first   An iterator
 * @param last    Another iterator.
 * @param comp    A functor to use for comparisons.
 * @return        Nothing.
 */
template <typename RandomAccessIterator, typename Compare>
void recursive_insertion_sort(RandomAccessIterator first,
                              RandomAccessIterator last, Compare comp) {
  if (std::distance(first, last) > 0) {
    recursive_insertion_sort(first, last - 1, comp);
    auto key = *(last - 1);
    auto p = last - 2;
    for (; p >= first && key < *p; --p) {
      std::iter_swap(p, p + 1);
    }
    *(p + 1) = key;
  }
}

/**
 * @brief Recursive insertion sort implementation.
 *
 * @param first   An iterator
 * @param last    Another iterator.
 * @return        Nothing.
 */
template <typename RandomAccessIterator>
void recursive_insertion_sort(RandomAccessIterator first,
                              RandomAccessIterator last) {
  recursive_insertion_sort(
      first, last,
      std::less<
          typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

// recursive_selection_sort

/**
 * @brief Recursively find selected candidate iterator based
 *        on compare functor.
 *
 * @param first   An iterator
 * @param last    Another iterator.
 * @param comp    A functor to use for comparisons.
 * @return        Selected iterator.
 */
template <typename RandomAccessIterator, typename Compare>
RandomAccessIterator find_selection(RandomAccessIterator first,
                                    RandomAccessIterator last, Compare comp) {
  if (first == last) {
    return first;
  }
  auto temp = find_selection(first + 1, last, comp);
  return comp(*first, *temp) ? first : temp;
}

/**
 * @brief Recursive selection sort implementation.
 *
 * @param first   An iterator
 * @param last    Another iterator.
 * @param comp    A functor to use for comparisons.
 * @return        Nothing.
 */
template <typename RandomAccessIterator, typename Compare>
void recursive_selection_sort(RandomAccessIterator first,
                              RandomAccessIterator last, Compare comp) {
  if (first != last) {
    auto temp = find_selection(first, last - 1, comp);
    if (first != temp) {
      std::iter_swap(first, temp);
    }
    recursive_selection_sort(first + 1, last, comp);
  }
}

/**
 * @brief Recursive selection sort implementation.
 *
 * @param first   An iterator
 * @param last    Another iterator.
 * @return        Nothing.
 */
template <typename RandomAccessIterator>
void recursive_selection_sort(RandomAccessIterator first,
                              RandomAccessIterator last) {
  recursive_selection_sort(
      first, last,
      std::less<
          typename std::iterator_traits<RandomAccessIterator>::value_type>());
}

} // namespace Sorting

} // namespace Analgo

#endif