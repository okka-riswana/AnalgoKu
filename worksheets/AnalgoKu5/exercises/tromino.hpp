#pragma once

#include <cstdio>
#include <cstdlib>

namespace Analgo {

/**
 * @brief tiles with right trominoes an nxn board with one square missing,
 *        assuming that n is a power of 2.
 *
 * @param x_board     x coordinate of board
 * @param y_board     y coordinate of board
 * @param x_missing   x coordinate of missing square
 * @param y_missing   y coordinate of missing square
 * @param board_size  size of the  the board
 * @return            Nothing.
 */
void tromino(int x_board, int y_board, int x_missing, int y_missing,
             int board_size) {
  int half_size = board_size / 2, x_center, y_center, x_upper_left,
      y_upper_left, x_upper_right, y_upper_right, x_lower_right, y_lower_right,
      x_lower_left, y_lower_left;

  if (board_size == 2) { /* 2x2 board */
    /* print position of tromino */
    printf("%d %d ", x_board + 1, y_board + 1);
    /* find and print orientation of tromino */
    if (x_board == x_missing)
      /* missing square in left half */
      if (y_board == y_missing)
        /* missing square in lower left */
        printf("UR\n");
      else
        /* missing square in upper left */
        printf("LR\n");
    else
        /* missing square in right half */
        if (y_board == y_missing)
      /* missing square in lower right */
      printf("UL\n");
    else
      /* missing square in upper right */
      printf("LL\n");
    return;
  }

  /* compute x and y coordinates of center of board */
  x_center = x_board + half_size;
  y_center = y_board + half_size;

  /* print position of special, center tromino */
  printf("%d %d ", x_center, y_center);

  /* Find and print orientation of center tromino.
     Also, set x_upper_left, y_upper_left, ... .  */
  if (x_missing < x_center) {
    /* missing square in left half */
    x_upper_right = x_lower_right = x_center;
    y_upper_right = y_center;
    y_lower_right = y_center - 1;
    if (y_missing < y_center) {
      /* missing square in lower left quadrant */
      printf("UR\n");
      x_upper_left = x_center - 1;
      y_upper_left = y_center;
      x_lower_left = x_missing;
      y_lower_left = y_missing;
    } else {
      /* missing square in upper left quadrant */
      printf("LR\n");
      x_upper_left = x_missing;
      y_upper_left = y_missing;
      x_lower_left = x_center - 1;
      y_lower_left = y_center - 1;
    }
  } else {
    /* missing square in right half */
    x_upper_left = x_lower_left = x_center - 1;
    y_upper_left = y_center;
    y_lower_left = y_center - 1;
    if (y_missing < y_center) {
      /* missing square in lower right quadrant */
      printf("UL\n");
      x_upper_right = x_center;
      y_upper_right = y_center;
      x_lower_right = x_missing;
      y_lower_right = y_missing;
    } else {
      /* missing square in upper right quadrant */
      printf("LL\n");
      x_upper_right = x_missing;
      y_upper_right = y_missing;
      x_lower_right = x_center;
      y_lower_right = y_center - 1;
    }
  }

  /* tile the four subboards */
  tromino(x_board, y_board + half_size, x_upper_left, y_upper_left, half_size);
  tromino(x_board + half_size, y_board + half_size, x_upper_right,
          y_upper_right, half_size);
  tromino(x_board + half_size, y_board, x_lower_right, y_lower_right,
          half_size);
  tromino(x_board, y_board, x_lower_left, y_lower_left, half_size);
}
} // namespace Analgo