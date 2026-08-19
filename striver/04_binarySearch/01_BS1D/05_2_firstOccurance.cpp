// given a sorted array with N integers
// write a program to find the first occurance of the target key
// return -1 if doesn't exist

#include <vector>

int firstOccurance(std::vector<int> &a, int x) {
  int n = a.size();
  int low = 0, high = n - 1;
  int latestOccurance = -1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (a[mid] == x) {
      latestOccurance = mid;
      high = mid - 1;
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
