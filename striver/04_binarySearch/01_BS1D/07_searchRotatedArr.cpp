// given a sorted array and a target element k,
// the array is rotated around some pivot (unknown),
// find the index at which k is present

#include <vector>

// the first solution to be given should be "Linear Search"

int searchRotated(std::vector<int> &a, int x) {
  int n = a.size();
  int low = 0, high = n - 1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (a[mid] == x) {
      return mid;
    }
    // checking if the left half is sorted or not
    if (a[low] <= a[mid]) {
      // now checking if the target exists on the left side or not
      if (a[low] <= x && x <= a[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    // now checking if the right half is sorted or not
    else if (a[mid] <= a[high]) {
      // now if the the target lies on the right side or not
      if (a[mid] <= x && x <= a[high]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
  }

  return -1;
}

int main(int argc, char *argv[]) {
  std::vector<int> array = {4, 5, 6, 7, 0, 1, 2};
  int target = 0;
  return 0;
}
