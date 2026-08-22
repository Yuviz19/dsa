// a peak element is the element that is strictly greater that both of its
// neighbours return the index of the peak element in the given un-sorted array
// if the array has multiple peaks, return any one of them

#include <vector>

int findPeakElement(std::vector<int> &a) {
  int n = a.size();
  if (n == 1)
    return 0;
  if (a[0] > a[1])
    return 0;
  if (a[n - 1] > a[n - 2])
    return n - 1;

  int low = 1, high = n - 2;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (a[mid] > a[mid - 1] && a[mid] > a[mid + 1])
      return mid;
    else if (a[mid] < a[mid + 1])
      low = mid + 1;
    else if (a[mid] < a[mid - 1])
      high = mid - 1;
    else // what if it is the bottom/lowest point on the curve, then we can go
         // in either direction
      high = mid - 1;
  }

  // dummy return
  return -1;
}

int main(int argc, char *argv[]) {
  std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
  // output -> 7
  return 0;
}
