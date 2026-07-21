// given a matrix
// rotate it by 180 deg

#include <algorithm>
#include <utility>
#include <vector>
// #include <iostream>

// this works for a rectangular matrix too
void rotate(std::vector<std::vector<int>> &a) {
  int m = a.size();

  for (int i = 0; i < m / 2; i++) {
    std::swap(a[i], a[m - i - 1]);
  }

  for (int i = 0; i < m; i++) {
    std::reverse(a[i].begin(), a[i].end());
  }
}

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  return 0;
}
