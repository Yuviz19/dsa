#include <algorithm>
#include <iostream>
#include <vector>

void rcrInsertion(std::vector<int> &a, int i) {
  if (i == a.size())
    return;
  int j = i;
  while (j > 0 && a[j - 1] > a[j]) {
    std::swap(a[j - 1], a[j]);
    j--;
  }
  rcrInsertion(a, ++i);
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {13, 46, 24, 52, 20, 9};

  rcrInsertion(arr, 0);

  for (int i : arr) {
    std::cout << i << " ";
  }
  return 0;
}
