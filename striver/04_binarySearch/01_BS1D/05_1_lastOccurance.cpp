// given a sorted array with N integers
// find the last occurance of the target element
// if it's not found, return the -1

#include <vector>

int lastOccuramce(std::vector<int> &a, int x) {
  int n = a.size();
  int low = 0, high = n - 1;
  int latestOccurance = -1;

  while (low <= high) {
    int mid = (low + high) / 2;
    if (a[mid] == x) {
      latestOccurance = mid;
      low = mid + 1;
    } else if (a[mid] > x) {
      high = mid - 1;
    } else
      low = mid + 1;
  }

  return latestOccurance;
}

int main(int argc, char *argv[]) {
  std::vector<int> array = {3, 4, 13, 13, 13, 20, 40};
  int target = 13;
  return 0;
}
