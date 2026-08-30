// Given an array nums, return true if the array was originally sorted in
// non-decreasing order, then rotated some number of positions (including zero).
// Otherwise, return false.

#include <vector>

bool isSortedII(std::vector<int> &a) {
  int n = a.size();
  int drop = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > a[(i + 1) % n]) {
      drop++;
    }
  }

  if (drop <= 1)
    return true;
  return false;
}

int main(int argc, char *argv[]) {
  std::vector<int> arrr = {3, 4, 5, 1, 2};
  return 0;
}
