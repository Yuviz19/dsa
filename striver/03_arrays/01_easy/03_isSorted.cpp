#include <iostream>
#include <vector>

// select a single and compoare it to its next (all) elements
bool isSortedBrute(std::vector<int> &a) {
  for (int i = 0; i < a.size(); i++) {
    for (int j = i + 1; j < a.size(); j++) {
      if (a[i] > a[j])
        return false;
    }
  }
  return true;
}

// start from 1, and compare the element, just before it
// if larger return false
bool isSortedOptimal(std::vector<int> &a) {
  for (int i = 1; i < a.size(); i++) {
    if (a[i] < a[i - 1])
      return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {1, 2, 3, 4, 5};
  if (isSortedBrute(arr))
    std::cout << "The array is sorted (via brute)" << "\n";

  if (isSortedOptimal(arr))
    std::cout << "The array is sorted (via optimal)" << "\n";

  return 0;
}
