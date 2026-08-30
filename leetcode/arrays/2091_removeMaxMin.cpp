// 2091 remove the elements from the front or from the back
#include <algorithm>
#include <climits>
#include <vector>

int minimumDeletions(std::vector<int> &nums) {
  int n = nums.size();
  if (n == 1)
    return 1;

  int maxEl = INT_MIN, minEl = INT_MAX;
  int maxInd = 0, minInd = 0;

  // to find the max and min element (with index)
  for (int i = 0; i < n; i++) {
    if (nums[i] > maxEl) {
      maxEl = nums[i];
      maxInd = i;
    }

    if (nums[i] < minEl) {
      minEl = nums[i];
      minInd = i;
    }
  }

  // for max
  int frontMax = maxInd + 1;
  int backMax = n - maxInd;

  // for min
  int frontMin = minInd + 1;
  int backMin = n - minInd;

  int bothFront = std::max(frontMax, frontMin);
  int bothBack = std::max(backMax, backMin);
  int maxFrontMinBack = frontMax + backMin;
  int minFrontMaxBack = backMax + frontMin;

  return std::min(bothBack, std::min(bothFront, std::min(maxFrontMinBack,
                                                         minFrontMaxBack)));
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {0, -4, 19, 1, 8, -2, -3, 5};
  return 0;
}
