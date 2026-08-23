// Given two numbers N and M, find the Nth root of M.
// The nth root of a number M is defined as a number X when raised to the power
// N equals M. if a perfect root doesn't exists, return -1

#include <cmath>

int findRoot(int n, int m) {
  int low = 1, high = m;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (std::pow(mid, n) == m)
      return mid;
    else if (std::pow(mid, n) < m)
      low = mid + 1;
    else
      high = mid - 1;
  }

  return -1;
}

int main(int argc, char *argv[]) {
  int n = 4, m = 69;
  return 0;
}
