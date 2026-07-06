#include <algorithm>
#include <iostream>
#include <vector>
// to find the elements that appears ones among twice occurering elements

int usingXOR(std::vector<int> &a) {
  int xorr = 0;

  // xor of an element with itself, will give 0 at some point,
  // but the single element does not get cancelled
  for (int i = 0; i < a.size(); i++) {
    xorr = xorr ^ a[i];
  }

  return xorr;
}

int usingHashArray(std::vector<int> &a) {
  int num;
  int highestNum = *std::max_element(a.begin(), a.end());
  std::vector<int> HashArray(highestNum + 1, 0);
  for (int i : a) {
    HashArray[i]++;
  }

  for (int i = 0; i <= highestNum + 1; i++) {
    if (HashArray[i] == 1)
      return i;
  }
  return -1;
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {4, 1, 2, 1, 2};
  std::cout << "Single element is " << usingXOR(arr);
  return 0;
}
