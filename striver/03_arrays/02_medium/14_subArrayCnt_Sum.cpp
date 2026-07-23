// Given an array of integers and an integer k,
//     return the total number of subarrays whose sum equals k.
// A subarray is a contiguous non-empty sequence of elements within an array.

#include <unordered_map>
#include <vector>
// #include <iostream

// trying brute force (nested loops)
int Brute(std::vector<int> &a, int k) {
  int count = 0;

  for (int i = 0; i < a.size(); i++) {
    int sum = 0;
    for (int j = i; j < a.size(); j++) {
      sum += a[j];

      if (sum == k)
        count++;
    }
  }

  return count;
}

// couting the number of arrays with all elements as positives
int posOptimal(std::vector<int> &a, int k) {
  int count = 0;
  int sum = 0;
  int i = 0, j = 0;

  while (i < a.size() && j < a.size()) {
    if (i < a.size()) {
      sum += a[i];
      i++;
    }

    if (sum == k) {
      count++;
    }

    while (sum > k) {
      sum -= a[j];
      j++;

      if (sum == k) {
        count++;
      }
    }
  }

  return count;
}

// counting subarrays with all kinds of elements
int Optimal(std::vector<int> &a, int k) {
  int count = 0, sum = 0;
  std::unordered_map<long long, int> preSum; // prefix sum, count
  preSum[sum] = 1;

  for (int i = 0; i < a.size(); i++) {
    sum += a[i];

    long long rem = sum - k;
    if (preSum.find(rem) != preSum.end()) {
      count += preSum[rem];
    }

    preSum[sum]++;
  }

  return count;
}

int main(int argc, char *argv[]) {
  std::vector<int> array = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};

  return 0;
}
