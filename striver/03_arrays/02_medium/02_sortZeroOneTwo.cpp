// sort an array that contains 0s, 1s and 2s as all it's elements

#include <iostream>
#include <utility>
#include <vector>

void sortZeroOneTwo(std::vector<int> &a) {
  int zCount = 0, oCount = 0, tCount = 0;

  for (int i = 0; i < a.size(); i++) {
    if (a[i] == 0)
      zCount++;
    else if (a[i] == 1)
      oCount++;
    else
      tCount++;
  }

  for (int i = 0; i < zCount; i++) {
    a[i] = 0;
  }

  for (int i = zCount; i < zCount + oCount; i++) {
    a[i] = 1;
  }

  for (int i = zCount + oCount; i < zCount + oCount + tCount; i++) {
    a[i] = 2;
  }
}

void sortZeroOneTwo2(std::vector<int> &a) {
  int left = 0, mid = 0, right = a.size() - 1;
  while (mid <= right) {
    if (a[mid] == 0) {
      std::swap(a[mid], a[left]);
      left++;
      mid++;
    } else if (a[mid] == 1) {
      mid++;
    } else {
      std::swap(a[mid], a[right]);
      right--;
    }
  }
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {1, 0, 2, 1, 0};
  sortZeroOneTwo(arr);
  for (auto i : arr) {
    std::cout << i << "\n";
  }
  return 0;
}
