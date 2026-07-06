#include <algorithm>
#include <iostream>
#include <vector>

// my approach - complexity = O(n x k)
void rotateArrayRight(std::vector<int> &a, int k) {
  for (int i = 0; i < k; i++) {
    int temp = a[a.size() - 1];
    for (int j = a.size() - 1; j > 0; j--) {
      a[j] = a[j - 1];
    }
    a[0] = temp;
  }
  for (int i : a) {
    std::cout << i << " ";
  }
}

// Time complexity - O(n) , but space complexity - O(k)
void rotateLeftBetter(std::vector<int> &a, int k) {
  k = k % a.size();
  if (a.size() == 0 || k == 0)
    return;

  std::vector<int> temp;
  // store starting k elements in temp
  for (int i = 0; i < k; i++) {
    temp.push_back(a[i]);
  }

  // start shigting
  for (int i = k; i < a.size(); i++) {
    a[i - k] = a[i];
  }

  // put back temp
  for (int i = a.size() - k; i < a.size(); i++) {
    a[i] = temp[i - a.size() + k];
  }

  for (int i : a) {
    std::cout << i << " ";
  }
}

void reverseArray(std::vector<int> &a, int start, int end) {
  while (start < end) {
    std::swap(a[start], a[end]);
    start++;
    end--;
  }
}

void rotateRightOptimal(std::vector<int> &nums, int k) {
  k = k % nums.size();
  if (nums.size() == 0 || k == 0)
    return;

  reverseArray(nums, nums.size() - k, nums.size() - 1);
  reverseArray(nums, 0, nums.size() - k - 1);
  reverseArray(nums, 0, nums.size() - 1);

  for (int i : nums) {
    std::cout << i << " ";
  }
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  std::vector<int> arEx = {-1, -100, 3, 99};
  // rotateArrayRight(arr, 2); -> my approach
  // rotateLeftBetter(arr, 2);
  rotateArrayRight(arEx, 2);

  return 0;
}
