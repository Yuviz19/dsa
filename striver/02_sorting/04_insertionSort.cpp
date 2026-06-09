#include <algorithm>
#include <array>
#include <iostream>
#include <utility>

void insertion_sort(int n, std::array<int, 6> a) {
  for (int i = 0; i <= n - 1; i++) {
    int j = i;
    while (j > 0 && a[j - 1] > a[j]) {
      std::swap(a[j - 1], a[j]);
      j--;
    }
  }

  for (int i : a) {
    std::cout << i << " ";
  }
}

int main(int argc, char *argv[]) {
  std::array<int, 6> arr = {13, 46, 24, 52, 20, 9};
  int n = arr.size();
  insertion_sort(n, arr);
  return 0;
}
