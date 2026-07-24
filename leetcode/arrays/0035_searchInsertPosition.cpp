// Given a sorted array of distinct integers and a target value, return the
// index if the target is found. If not, return the index where it would be if
// it were inserted in order.

#include <vector>

int binarySeach(std::vector<int> &a, int k, int low, int high) {
  int mid = (low + high) / 2;

  if (high >= low) {
    if (a[mid] == k) {
      return mid;
    }
    if (k > a[mid]) {
      return binarySeach(a, k, mid + 1, high);
    }
    if (k < a[mid]) {
      return binarySeach(a, k, low, mid - 1);
    }
  }

  if (a[mid] < k) {
    return mid + 1;
  }

  return mid;
}

// classic example of binary ssarch
int searchInsert(std::vector<int> &a, int target) {
  int low = 0;
  int high = a.size() - 1;

  int index = binarySeach(a, target, low, high);

  return index;
}

int main(int argc, char *argv[]) {
  std::vector<int> array = {1, 3, 5, 6};
  return 0;
}
