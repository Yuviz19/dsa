// split array largest sum
// Given an integer array nums and an integer k,
// split nums into k non-empty subarrays such that
// the largest sum of any subarray is minimized.

// return the largest sum

#include <algorithm>
#include <vector>

long long sum(std::vector<int> &nums) {
  long long ans = 0;
  for (int i = 0; i < nums.size(); i++) {
    ans += nums[i];
  }

  return ans;
}

bool isValid(std::vector<int> &nums, int k, int i) {
  int count = 1;
  int sum = 0;
  int n = nums.size();
  for (int j = 0; j < n; j++) {
    if (sum + nums[j] <= i) {
      sum += nums[j];
    } else {
      count++;
      sum = nums[j];
    }
  }

  if (count > k) {
    return false;
  }

  return true;
}

int splitArray(std::vector<int> &nums, int k) {
  int n = nums.size();
  if (n == 0) {
    return 0;
  }
  int low = *std::max_element(nums.begin(), nums.end());
  long long high = sum(nums);
  long long ans = 0;

  while (low <= high) {
    long long mid = (low + high) / 2;
    // keeping the max sum cap
    if (isValid(nums, k, mid)) {
      high = mid - 1;
      ans = mid;
    } else {
      low = mid + 1;
    }
  }

  return ans;
}

int main(int argc, char *argv[]) {
  std::vector<int> nums = {7, 2, 5, 10, 8};
  int k = 2;
  return 0;
}
