// Given an array Arr[] of integers, rearrange the numbers of the given array
// into the lexicographically next greater permutation of numbers. If such an
// arrangement is not possible, it must rearrange to the lowest possible order
// (i.e., sorted in ascending order).

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

std::vector<int> brute(std::vector<int> &a) {
  // generate all the permutations
  std::vector<std::vector<int>> allPermutations;
  std::vector<int> temp = a;

  do {
    allPermutations.push_back(a);
  } while (std::next_permutation(a.begin(), a.end()));

  for (int i = 0; i < allPermutations.size(); i++) {
    if (allPermutations[i] == temp) {
      if (i == allPermutations.size() - 1) {
        std::sort(temp.begin(), temp.end());
        return temp;
      }

      return allPermutations[i + 1];
    }
  }

  return temp;
}

// the entire above solution boils down to
// if (!next_permutation(a.begin(), a.end()))
//    sort(a.begin(), a.end())
// return a;

void optimal(std::vector<int> &a) {
  // finding breakpoint
  int index = -1;
  for (int i = a.size() - 2; i >= 0; i--) {
    if (a[i] < a[i + 1]) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    std::reverse(a.begin(), a.end());
    return;
  }

  for (int i = a.size() - 1; i >= index + 1; i--) {
    if (a[i] > a[index]) {
      std::swap(a[i], a[index]);
      break;
    }
  }

  // sort the remaining part of the array
  std::reverse(a.begin() + index + 1, a.end());
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {1, 3, 2};
  return 0;
}
