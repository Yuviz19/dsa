// given a sorted array and a target integer x
// find floor -> largest element which is smaller or equal to x
// ceil -> smallest element which is greater than or equal to x

#include <vector>

int findFloor(std::vector<int> &a, int x) {
  int n = a.size();
  int low = 0, high = n - 1;
  int floor = 0;

  while (low <= high) {
    int mid = (low + high) / 2;
    if (a[mid] <= x) {
      floor = a[mid];
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return floor;
}

int findCeil(std::vector<int> &a, int x) {
  int n = a.size();
  int low = 0, high = n - 1;
  int ceil = n;

  while (low <= high) {
    int mid = (low + high) / 2;
    if (a[mid] >= x) {
      ceil = a[mid];
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return ceil;
}

int main(int argc, char *argv[]) {
  std::vector<int> array = {3, 4, 4, 7, 8, 10};
  int x = 5;
  return 0;
}
