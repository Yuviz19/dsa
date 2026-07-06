#include <iostream>
#include <vector>

int linearSearch(std::vector<int> &a, int t) {
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == t)
      return i;
  }
  return -1;
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {5, 4, 3, 2, 1};
  // let, element to find => 5
  int targetIndex = linearSearch(arr, 5);
  std::cout << "Terget found at index: " << targetIndex;
  return 0;
}
