//  Given an integer array nums, find the subarray with the largest sum and
//  return the sum of the elements present in that subarray

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int brute(std::vector<int> &a) {
  int maxi = 0;
  for (int i = 0; i < a.size(); i++) {
    int sum = 0;
    for (int j = i; j < a.size(); j++) {
      sum += a[j];
      maxi = std::max(maxi, sum);
    }
  }

  return maxi;
}

int optimal(std::vector<int> &a) {
  int maxi = INT_MIN, sum = 0;

  for (int i = 0; i < a.size(); i++) {
    sum += a[i];
    maxi = std::max(sum, maxi);

    if (sum < 0) {
      sum = 0;
    }
  }

  return maxi;
}

// printing the subarray with the max sum
std::vector<int> kadane(std::vector<int> &a) {
  int maxi = INT_MIN, sum = 0;
  int start = 0; // to keep track of the starting of current subarray
  int ansStart = -1, ansEnd = -1; // to note the indices of the subarray

  for (int i = 0; i < a.size(); i++) {
    if (sum == 0) {
      start = i;
    }

    sum += a[i];

    if (sum > maxi) {
      maxi = sum;
      ansStart = start;
      ansEnd = i;
    }

    if (sum < 0) {
      sum = 0;
    }
  }

  return {ansStart, ansEnd};
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {2, 3, 5, -2, 7, -4}; // 15 (index 0 to index 4)
  // std::cout << brute(arr) << "\n";
  // std::cout << optimal(arr) << "\n";

  std::vector<int> startEnd = kadane(arr);

  for (int i = startEnd[0]; i <= startEnd[1]; i++) {
    std::cout << arr[i] << " ";
  }

  return 0;
}
