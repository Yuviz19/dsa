// Given an array nums of size n (ONLY POSITIVES) and an integer k,
// find the length of the longest sub-array that sums to k.
// If no such sub-array exists, return 0.

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

// time -> O(n^2) and time -> O(1)
int Brute(std::vector<int> &a, int k) {
  int longest = 0;

  for (int i = 0; i < a.size(); i++) {
    int sum = 0;
    for (int j = i; j < a.size(); j++) {
      sum += a[j];
      if (sum == k) {
        longest = std::max(longest, (j - i + 1));
      }
    }
  }

  return longest;
}

// Optimal approach uses the concept of prefix sum (complexity - O(n) and space
// O(n)) but this is not valid for arrays with negatives and zeros
// this is the optimal solution for an array with positives, negatives and zeros
int Better(std::vector<int> &a, long long k) {
  int longest = 0;
  long long sum = 0;
  std::unordered_map<long long, int> preOrderSum;
  int maxLen = 0;
  int count = 0;

  for (int i = 0; i < a.size(); i++) {
    sum += a[i];
    if (sum == k) {
      maxLen = std::max(maxLen, i + 1);
      count++;
    }

    long long rem = sum - k;
    if (preOrderSum.find(rem) != preOrderSum.end()) {
      int len = i - preOrderSum[rem];
      maxLen = std::max(maxLen, len);
      count++;
    }

    if (preOrderSum.find(sum) == preOrderSum.end())
      preOrderSum[sum] = i;
  }

  return maxLen;
}

// 2 pointer approach -> only works for array with positives (not even zeros)
int Optimal(std::vector<int> &a, int k) {
  int longest = 0;
  int sum = 0;
  int i = 0, j = 0;

  while (i < a.size() && j < a.size()) {
    if (i < a.size()) {
      sum += a[i];
      i++;
    }

    if (sum == k) {
      longest = std::max(longest, i - j);
    }

    while (sum > k) {
      sum -= a[j];
      j++;

      if (sum == k) {
        longest = std::max(longest, i - j);
      }
    }
  }

  return longest;
}

int main(int argc, char *argv[]) {
  std::vector<int> PostiveArr = {10, 5, 2, 7, 1, 9};
  int k = 15;
  std::cout << "longest: " << Brute(PostiveArr, k);

  return 0;
}
