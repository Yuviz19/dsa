// given an integer array (distinct values) and it is rotated around an unknown
// index find the minimum element in the array

#include <algorithm>
#include <climits>
#include <vector>

// brute
int minBrute(std::vector<int> &a) {
  int min = INT_MAX;
  for (int i = 0; i < a.size(); i++) {
    min = std::min(a[i], min);
  }

  return min;
}

int minBinarySearch(std::vector<int> &a) {
  int n = a.size();
  int low = 0, high = n - 1;
  int ans = INT_MAX;

  while (low <= high) {
    int mid = (low + high) / 2;
    // now look which ever part is sorted,
    // eleminate that part, before that take the minimum of that part

    // the left part is sorted
    if (a[low] <= a[mid]) {
      ans = std::min(a[low], ans);
      low = mid + 1;
    } else {
      ans = std::min(a[mid], ans);
      high = mid - 1;
    }
  }

  return ans;
}

int main(int argc, char *argv[]) {
  std::vector<int> array = {4, 5, 6, 7, 0, 1, 2, 3};
  // output => 0
  return 0;
}
