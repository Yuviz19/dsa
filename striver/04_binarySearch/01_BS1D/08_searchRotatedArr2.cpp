// similar to searching in the rotated array,
// but here the array has duplicate elements too
// also this time just return true or false

#include <vector>

// first solution is always linear search

bool searchRotated(std::vector<int> &a, int x) {
  int n = a.size();
  int low = 0, high = n - 1;

  while (low <= high) {
    int mid = (low + high) / 2;
    // is the element found
    if (a[mid] == x)
      return true;

    if (a[low] == a[mid] && a[mid] == a[high]) {
      low = low + 1;
      high = high - 1;
      continue;
    }

    // is the left side sorted
    if (a[low] <= a[mid]) {
      // is the element in this part of the array
      if (a[low] <= x && x <= a[mid]) {
        high = mid - 1;
      } else
        low = mid + 1;
    }

    // the right might be sorted
    else {
      // does the element exists in this side of the array
      if (a[mid] <= x && x <= a[high]) {
        low = mid + 1;
      } else
        high = mid - 1;
    }
  }

  return false;
}

int main(int argc, char *argv[]) {
  std::vector<int> array = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
  int target = 3;
  return 0;
}
