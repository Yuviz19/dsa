// Lower Bound -> smallest index such that arr[mid] >= x

#include <vector>

// finding the Lower bound
int lowerBound(std::vector<int> &a, int x) {
  int n = a.size();
  int low = 0, high = n - 1;
  int ans = n;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (x <= a[mid]) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return ans;
}

// Upper Bound -> first index where a[i] > target

// finding the Upper bound
int upperBound(std::vector<int> &a, int target) {
  int n = a.size();
  int low = 0, high = n - 1;
  int ans = n;

  while (low <= high) {
    int mid = (low + high) / 2;
    if (target < a[mid]) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return ans;
}

int main(int argc, char *argv[]) {
  std::vector<int> array = {1, 2, 3, 3, 7, 8, 9, 9, 9, 11};
  return 0;
}
