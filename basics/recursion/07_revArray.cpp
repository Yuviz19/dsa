#include <iostream>
#include <utility>
#include <vector>

std::vector<int> revArr(std::vector<int> &a, int left, int right) {
  if (left >= right) {
    return a;
  }
  std::swap(a[left], a[right]);
  return revArr(a, left + 1, right - 1);
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {5, 4, 3, 2, 1};
  std::vector<int> newArr = revArr(arr, 0, arr.size() - 1);

  for (auto r : newArr) {
    std::cout << r << " ";
  }
  return 0;
}
