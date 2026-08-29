// You are given an array of integers 'arr' and an integer i.e. a threshold
// value 'limit'. Your task is to find the smallest positive integer divisor,
// such that upon dividing all the elements of the given array by it, the sum of
// the division's result is less than or equal to the given threshold value.

#include <algorithm>
#include <vector>

int sumOfDiv(std::vector<int> &a, int k) {
  int sum = 0;
  for (int i = 0; i < a.size(); i++) {
    sum += (a[i] + k - 1) / k;
  }

  return sum;
}

int brute(std::vector<int> &a, int limit) {
  int high = *std::max_element(a.begin(), a.end());
  for (int i = 1; i <= high; i++) {
    int result = sumOfDiv(a, i);
    if (result <= limit)
      return i;
  }

  return -1;
}

int smallestDivisor(std::vector<int> &nums, int threshold) {
  int low = 1, high = *std::max_element(nums.begin(), nums.end());
  int ans;
  while (low <= high) {
    int mid = (low + high) / 2;
    int result = sumOfDiv(nums, mid);

    if (result <= threshold) {
      ans = mid;
      high = mid - 1;
    } else
      low = mid + 1;
  }

  return ans;
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {1, 2, 3, 4, 5};
  int limit = 8;
  return 0;
}
