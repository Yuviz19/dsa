// Given an array of integers A and an integer B.
// Find the total number of subarrays having bitwise XOR of all elements equal
// to k.

#include <map>
#include <vector>

int brute(std::vector<int> &a, int k) {
  int n = a.size();
  int count = 0;

  for (int i = 0; i < n; i++) {
    int xork = 0;
    for (int j = i; j < n; j++) {
      xork ^= a[j];
      if (xork == k)
        count++;
    }
  }

  return count;
}

// tiem -> O(nlogn) ans space O(n)
int optimal(std::vector<int> &a, int k) {
  int count = 0;
  std::map<int, int> preXor;
  int xork = 0;
  preXor[xork]++; // {0, 1}

  for (int i = 0; i < a.size(); i++) {
    xork ^= a[i];

    int remaining = xork ^ k;
    if (preXor.find(remaining) != preXor.end()) {
      count += preXor[remaining];
    }

    preXor[xork]++;
  }

  return count;
}

int main(int argc, char *argv[]) {
  std::vector<int> array = {4, 2, 2, 6, 4};
  int target = 6;

  return 0;
}
