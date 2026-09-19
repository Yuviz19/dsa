// find the median of 2 sorted arrays

#include <algorithm>
#include <climits>
#include <vector>

// brute force - using merge sort
double brute(std::vector<int> &nums1, std::vector<int> &nums2) {
  int n1 = nums1.size();
  int n2 = nums2.size();
  std::vector<int> temp;

  int i = 0, j = 0;
  while (i < n1 && j < n2) {
    if (nums1[i] < nums2[j]) {
      temp.push_back(nums1[i]);
      i++;
    } else {
      temp.push_back(nums2[j]);
      j++;
    }
  }

  while (i < n1) {
    temp.push_back(nums1[i]);
    i++;
  }

  while (j < n2) {
    temp.push_back(nums2[j]);
    j++;
  }

  double ans = 0;

  if ((n1 + n2) % 2 == 0) {
    ans = (double)(temp[(n1 + n2) / 2] + temp[((n1 + n2) / 2) - 1]) / 2;
  } else {
    ans = (double)temp[(n1 + n2) / 2];
  }

  return ans;
}

// merge sort without space complexity
double better(std::vector<int> &nums1, std::vector<int> &nums2) {
  int n1 = nums1.size();
  int n2 = nums2.size();
  int n = n1 + n2;
  int i = 0, j = 0;
  int prev = 0, curr = 0;
  int count = 0;

  while (i < n1 && j < n2) {
    if (nums1[i] < nums2[j]) {
      prev = curr, curr = nums1[i], count++;
      i++;
    } else {
      prev = curr, curr = nums2[j], count++;
      j++;
    }

    if (count > n / 2) {
      break;
    }
  }

  int median;

  if (n % 2 == 0) {
    median = (prev + curr) / 2.0;
  } else {
    median = curr;
  }

  return median;
}

// using binary search for the optimal appraoch
double findMedianSortedArrays(std::vector<int> &nums1,
                              std::vector<int> &nums2) {
  int n1 = nums1.size();
  int n2 = nums2.size();
  int n = n1 + n2;

  // we want to have the smaller array to the left
  if (n1 > n2)
    findMedianSortedArrays(nums2, nums1);
  int low = 0, high = n1;
  int left = (n1 + n2 + 1) / 2;

  while (low <= high) {
    int mid1 = (low + high) / 2;
    int mid2 = left - mid1;

    int l1 = INT_MIN, l2 = INT_MIN;
    int r1 = INT_MAX, r2 = INT_MAX;

    if (mid1 < n1)
      r1 = nums1[mid1];
    if (mid2 < n2)
      r2 = nums2[mid2];
    if (mid1 - 1 >= 0)
      l1 = nums1[mid1 - 1];
    if (mid2 - 1 >= 0)
      l2 = nums2[mid2 - 1];

    if (l1 <= r1 && l2 <= r2) {
      if (n % 2 == 1)
        return std::max(l1, l2);
      return (double)(std::max(l1, l2) + std::min(r1, r2)) / 2.0;
    } else if (l1 > r2) {
      high = mid1 - 1;
    } else {
      low = mid1 + 1;
    }
  }

  return 0;
}

int main(int argc, char *argv[]) {
  std::vector<int> arr1 = {7, 12, 14, 15};
  std::vector<int> arr2 = {1, 2, 3, 4, 9, 11};
  return 0;
}
