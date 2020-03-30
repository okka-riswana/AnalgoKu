#include <cmath>
#include <iostream>

size_t getLength(uint64_t value) {
  size_t counter = 0;
  while (value != 0) {
    counter++;
    value /= 10;
  }
  return counter;
}

uint64_t multiply(uint64_t x, uint64_t y) {
  size_t xLength = getLength(x);
  size_t yLength = getLength(y);

  size_t n = (size_t)(std::fmax(xLength, yLength));

  if (n < 10) {
    return x * y;
  }

  n = (n / 2) + (n % 2);

  uint64_t multiplier = std::pow(10, n);

  uint64_t b = x / multiplier;
  uint64_t a = x - (b * multiplier);
  uint64_t d = y / multiplier;
  uint64_t c = y - (d * n);

  uint64_t z0 = multiply(a, c);
  uint64_t z1 = multiply(a + b, c + d);
  uint64_t z2 = multiply(b, d);

  return z0 + ((z1 - z0 - z2) * multiplier) +
         (z2 * (uint64_t)(std::pow(10, 2 * n)));
}

int main() {
  uint64_t a = 2406994;
  uint64_t b = 2328563;
  std::cout << multiply(a, b) << std::endl;
  return 0;
}