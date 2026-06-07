#include <algorithm>
#include <array>
#include <iostream>

void bubbleSort(int n, std::array<int, 6> a) {
  for (int i = n - 1; i >= 1; i--) {
    int ifSorted = 0;
    for (int j = 0; j < i; j++) {
      if (a[j] > a[j + 1]) {
        std::swap(a[j], a[j + 1]);
        ifSorted = 1;
      }
    }

    if (ifSorted == 0) {
      break;
    }
  }

  for (int i : a) {
    std::cout << i << " ";
  }
}

int main(int argc, char *argv[]) {
  std::array<int, 6> arr = {13, 46, 24, 52, 20, 9};
  int n = arr.size();
  bubbleSort(n, arr);
  return 0;
}
