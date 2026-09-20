// to find the kth element of 2 sorted arrays

#include <algorithm>
#include <climits>
#include <vector>

// one approach is directly making a new array with merger sort
// then returning the kth element

// the merge sort approach
// withour making a new array
int mergeApproach(std::vector<int> &a, std::vector<int> &b, int k) {
  int n1 = a.size();
  int n2 = b.size();
  int count = 0;
  int ans = 0;

  int i = 0, j = 0;
  while (i < n1 && j < n2) {
    if (a[i] <= b[j]) {
      ans = a[i];
      count++;
      i++;
    } else {
      ans = b[j];
      count++;
      j++;
    }

    if (count == k) {
      return ans;
    }
  }

  // if elements are remaining
  while (i < n1) {
    ans = a[i];
    i++;
    count++;

    if (count == k) {
      return ans;
    }
  }

  while (j < n2) {
    ans = a[j];
    j++;
    count++;

    if (count == k) {
      return ans;
    }
  }

  // dummy return
  return -1;
}

// using binary search
int binarySearchApproach(std::vector<int> &a, std::vector<int> &b, int k) {
  int n1 = a.size(), n2 = b.size();
  int n = n1 + n2;

  // keeping smaller on the left
  if (n2 < n1) {
    return binarySearchApproach(b, a, k);
  }

  int low = std::max(0, k - n2), high = std::min(k, n1);
  int left = k;
  while (low <= high) {
    int mid1 = (low + high) / 2;
    int mid2 = left - mid2;

    int l1 = INT_MIN, l2 = INT_MIN;
    int r1 = INT_MAX, r2 = INT_MAX;

    if (mid1 < n1)
      r1 = a[mid1];
    if (mid2 < n2)
      r2 = b[mid2];
    if (mid1 - 1 >= 0)
      l1 = a[mid1 - 1];
    if (mid2 - 1 >= 0)
      l2 = b[mid2 - 1];

    if (l1 <= r2 && l2 <= r1) {
      return std::max(l1, l2);
    } else if (l1 > r2) {
      high = mid1 - 1;
    } else {
      low = mid1 + 1;
    }
  }

  return -1;
}

int main(int argc, char *argv[]) {
  std::vector<int> arr1 = {2, 3, 6, 7, 9};
  std::vector<int> arr2 = {1, 4, 8, 10};
  int k = 5;
  return 0;
}
