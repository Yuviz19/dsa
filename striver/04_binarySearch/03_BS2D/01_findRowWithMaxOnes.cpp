// given a matrix of 0s/1s
// to find the row with max number of ones
// also given that every row of the array is sorted

#include <algorithm>
#include <vector>

// one of the solution is to find the max of each row and update and return the
// answer O(n^2)

// so using the binary search
// to find the row and then for each row
// find the max ones via binary search
// O(n*logm)

int binaryHelper(std::vector<int> &b) {
  int m = b.size();
  int low = 0, high = m - 1;
  int ans = 0;
  int k = 1;

  while (low <= high) {
    int mid = (low + mid) / 2;
    if (b[mid] == k) {
      int count = m - mid;
      ans = std::max(count, ans);
      high = mid - 1;
    } else
      low = mid - 1;
  }

  return ans;
}

int rowWithMax1s(std::vector<std::vector<int>> &a) {
  int n = a.size();
  int m = a[0].size();
  int ans = -1;
  int row = -1;

  for (int i = 0; i < n; i++) {
    int currAns = -1;
    int currInd = i;

    currAns = binaryHelper(a[i]);
    if (currAns <= ans) {
      row = std::min(row, currInd);
    }
    ans = std::max(currAns, ans);
  }

  return row;
}

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> array = {
      {0, 0, 1, 1}, {0, 1, 1, 1}, {0, 0, 0, 1}};
  return 0;
}
