// Given an array containing both positive and negative integers,
// we have to find the length of the longest subarray with the sum of all
// elements equal to zero.

#include <algorithm>
#include <unordered_map>
#include <vector>

// checking all subarrays to do so
int brute(std::vector<int> &a) {
  int maxLen = 0;
  int n = a.size();

  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += a[j];
      if (sum == 0) {
        maxLen = std::max(maxLen, j - i + 1);
      }
    }
  }
  return maxLen;
}

int optimal(std::vector<int> &a) {
  int maxLen = 0;
  int n = a.size();
  int sum = 0;
  std::unordered_map<int, int> preSum;

  for (int i = 0; i < n; i++) {
    sum += a[i];

    if (sum == 0) {
      maxLen = std::max(maxLen, i + 1);
    } else {
      if (preSum.find(sum) != preSum.end()) {
        int len = i - preSum[sum];
        maxLen = std::max(maxLen, len);
      } else
        preSum[sum] = i;
    }
  }

  return maxLen;
}

int main(int argc, char *argv[]) {
  std::vector<int> array = {9, -3, 3, -1, 6, -5};
  return 0;
}
