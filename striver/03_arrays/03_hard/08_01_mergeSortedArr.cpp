// this is the striver side of the question
// Given two sorted integer arrays nums1 and nums2, merge both the arrays into a
// single array sorted in non-decreasing order. The final sorted array should be
// stored inside the array nums1 and it should be done in-place. and if there is
// an overflow, store it into nums2

#include <algorithm>
#include <utility>
#include <vector>

// this uses extra space
void mergeApproach01(std::vector<int> &a, std::vector<int> &b) {
  int n = a.size();
  int m = b.size();
  std::vector<int> newArr;
  int left = 0;
  int right = 0;
  int index = 0;

  while (left < n && right < m) {
    if (a[left] <= b[right]) {
      newArr[index++] = a[left++];
    } else {
      newArr[index++] = b[right++];
    }
  }

  while (left < n) {
    newArr[index++] = a[left++];
  }
  while (right < m) {
    newArr[index++] = b[right++];
  }

  for (int i = 0; i < n + m; i++) {
    if (i < n)
      a[i] = newArr[i];
    else
      b[i - n] = newArr[i];
  }
}

void mergeApproach02(std::vector<int> &a, std::vector<int> &b) {
  int n = a.size(), m = b.size();
  int left = n - 1, right = 0;

  while (left >= 0 && right < m) {
    if (a[left] > b[right]) {
      std::swap(a[left], b[right]);
      left--, right++;
    } else
      break;
  }

  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());
}

// helper function for 03 approach
void swapIfGreater(std::vector<int> &a, std::vector<int> &b, int ind1,
                   int ind2) {
  if (a[ind1] > b[ind2]) {
    std::swap(a[ind1], b[ind2]);
  }
}

// using the gap method (based on shell sort)
void mergeApproach03(std::vector<int> &a, std::vector<int> &b) {
  int n = a.size(), m = b.size();
  int len = (n + m);
  int gap = (len / 2) + (len % 2);
  while (gap > 0) {
    int left = 0, right = left + gap;
    while (right < len) {
      // in a and b simultaneously
      if (left < n && right >= n) {
        swapIfGreater(a, b, left, right - n);
      } else if (left >= n) {
        // both in b
        swapIfGreater(b, b, left - n, right - n);
      } else {
        // both in a
        swapIfGreater(a, a, left, right);
      }
      left++, right++;
    }

    if (gap == 1)
      break;
    gap = (gap / 2) + (gap % 2);
  }
}

int main(int argc, char *argv[]) {
  std::vector<int> nums1 = {-5, -2, 4, 5, 0, 0, 0};
  std::vector<int> nums2 = {-3, 1, 8};
  return 0;
}
