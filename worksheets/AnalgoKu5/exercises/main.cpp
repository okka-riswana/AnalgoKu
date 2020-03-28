#include "tromino.hpp"
#include <cstdio>

/**
 * "C" implementation for Tromino tiling problem.
 *
 * maaf acak-acakan
 */
int main(int argc, char const **argv) {
  int board_size, x_missing, y_missing;
  do {
    puts("\n-------------------------------------");
    puts("\nEnter size of board (0 to quit): ");
    scanf("%d", &board_size);
    if (board_size) {
      printf("\nEnter coordinates of missing square (space sep.): ");
      scanf("%d%d", &x_missing, &y_missing);
      puts("\n\nTiling\n------");
      Analgo::tromino(0, 0, x_missing, y_missing, board_size);
    }
  } while (board_size);

  return EXIT_SUCCESS;
