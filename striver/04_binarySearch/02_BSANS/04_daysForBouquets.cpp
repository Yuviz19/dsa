// question statement
// You are given 'N’ roses and you are also given an array 'arr' where 'arr[i]'
// denotes that the 'ith' rose will bloom on the 'arr[i]th' day. You can only
// pick already bloomed roses that are adjacent to make a bouquet. You are also
// told that you require exactly 'k' adjacent bloomed roses to make a single
// bouquet. Find the minimum number of days required to make at least ‘m'
// bouquets each containing 'k' roses. Return -1 if it is not possible.

#include <algorithm>
#include <vector>

int calculateConDays(std::vector<int> &a, int day, int k) {
  int count = 0;
  int conCount = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] <= day) {
      conCount++;
    } else
      conCount = 0;
    if (conCount == k) {
      count++;
      conCount = 0;
    }
  }
  return count;
}

// brute force
int minDaysBrute(std::vector<int> &a, int m, int k) {
  if (a.size() < (1LL * m * k))
    return -1;

  int maxDay = *std::max_element(a.begin(), a.end());
  int minDay = *std::min_element(a.begin(), a.end());

  for (int i = minDay; i <= maxDay; i++) {
    // for checking if we have the consiqutive days
    if (calculateConDays(a, i, k) == m) {
      return i;
    }
  }

  return -1;
}

int minDays(std::vector<int> &bloomDay, int m, int k) {
  if (bloomDay.size() < (1ll * m * k))
    return -1;

  int low = *std::min_element(bloomDay.begin(), bloomDay.end());
  int high = *std::max_element(bloomDay.begin(), bloomDay.end());
  int ans = -1;

  while (low <= high) {
    int mid = (low + high) / 2;
    int count = calculateConDays(bloomDay, mid, k);

    if (count >= m) {
      high = mid - 1;
      ans = mid;
    } else
      low = mid + 1;
  }

  return ans;
}

int main(int argc, char *argv[]) {
  std::vector<int> bloomDay = {7, 7, 7, 7, 13, 11, 12, 7};
  int m = 2;
  int k = 3;
  return 0;
}
