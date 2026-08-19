// given a sorted array of distinct values and a target x
// return the index of the target element
#include <vector>

// this is truely based on lower bound
int insertPos(std::vector<int> &a, int x) {
  int n = a.size();
  int low = 0;
  int high = n - 1;
  int ans = n;

  while (low <= high) {
    int mid = (low + high) / 2;
    if (a[mid] >= x) {
      ans = mid;
      high = mid - 1;
    } else
      low = mid + 1;
  }

  return ans;
}

int main(int argc, char *argv[]) {
  std::vector<int> array = {1, 2, 5, 7};
  int x = 6;
  insertPos(array, x);
  return 0;
}
