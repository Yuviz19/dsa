// given a sorted rotated array
// find out how many times the array has been rotated

#include <climits>
#include <vector>

int RotationNumber(std::vector<int> &a) {
  int n = a.size();
  int low = 0, high = n - 1;
  int minElement = INT_MAX;
  int ans = 0;

  while (low <= high) {
    int mid = (low + high) / 2;

    // checling if the left side is sorted
    if (a[low] <= a[mid]) {
      if (a[low] < minElement) {
        minElement = a[low];
        ans = low;
      }
      low = mid + 1;
    } else {
      if (a[mid] < minElement) {
        minElement = a[mid];
        ans = mid;
      }
      high = mid - 1;
    }
  }

  return ans;
}

int main(int argc, char *argv[]) {
  std::vector<int> array = {4, 5, 6, 7, 0, 1, 2, 3};
  // output => 4
  return 0;
}
