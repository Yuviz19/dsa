// to find the peak element that is greater than its adjacent elements
// to find the solution in O(n logm) or O(m logn)

#include <vector>

int findCol(std::vector<int> &b) {
  int m = b.size();
  int maxInd = -1;
  int maxEl = -1;

  for (int i = 0; i < m; i++) {
    int index = -1;
    if (b[i] >= maxEl) {
      maxEl = b[i];
      maxInd = i;
    }
  }

  return maxInd;
}

std::vector<int> findPeakGrid(std::vector<std::vector<int>> &a) {
  int n = a.size();
  int m = a[0].size();

  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    // finding the max element in that row
    int col = findCol(a[mid]);
    int top = (mid - 1 >= 0) ? a[mid - 1][col] : -1;
    int bottom = (mid + 1 < n) ? a[mid + 1][col] : -1;

    if (a[mid][col] > top && a[mid][col] > bottom) {
      return {mid, col};
    } else if (a[mid][col] < top) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return {-1, -1};
}

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> array = {
      {10, 20, 15}, {21, 30, 14}, {7, 16, 32}};
  return 0;
}
