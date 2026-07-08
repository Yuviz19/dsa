// There’s an array ‘A’ of size ‘N’ with an equal number of positive and
// negative elements. Without altering the relative order of positive and
// negative elements, you must return an array of alternately positive and
// negative values.

#include <iostream>
#include <vector>

void brute(std::vector<int> &a) {
  std::vector<int> positives;
  std::vector<int> negatives;

  for (int i = 0; i < a.size(); i++) {
    if (a[i] >= 0) {
      positives.push_back(a[i]);
    } else {
      negatives.push_back(a[i]);
    }
  }

  for (int j = 0; j < a.size() / 2; j++) {
    a[2 * j] = positives[j];
    a[2 * j + 1] = negatives[j];
  }
}

std::vector<int> optimal(std::vector<int> &a) {
  int n = a.size();
  int posIndex = 0, negIndex = 1;
  std::vector<int> result(n);

  for (int i = 0; i < n; i++) {
    if (a[i] >= 0) {
      result[posIndex] = a[i];
      posIndex += 2;
    } else {
      result[negIndex] = a[i];
      negIndex += 2;
    }
  }

  return result;
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {1, 2, -3, -1, -2, 3}; // 1 -3 2 -1 3 -2

  return 0;
}
