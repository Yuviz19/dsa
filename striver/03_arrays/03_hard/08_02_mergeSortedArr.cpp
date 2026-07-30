// this is the leetcode side of the priblem
// we have to sort the two arrays but within the first one,
// and only sort till the number specifies

#include <vector>

void myapproch(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
  int i = m - 1, j = n - 1, k = m + n - 1;
  while (i >= 0 && j >= 0) {
    if (nums1[i] > nums2[j]) {
      nums1[k] = nums1[i];
      k--, i--;
    } else {
      nums1[k] = nums2[j];
      k--, j--;
    }
  }
  while (j >= 0) {
    nums1[k] = nums2[j];
    j--;
    k--;
  }
}

int main(int argc, char *argv[]) {
  std::vector<int> num1 = {1, 2, 3, 0, 0, 0}, num2 = {2, 5, 6};
  int m = 3, n = 3;
  return 0;
}
