// this version says that both the rows and colums are sorted
// return a boolean

#include <vector>

bool searchMatrix(std::vector<std::vector<int>> &a, int k) {
  int n = a.size();
  int m = a[0].size();

  int i = 0, j = m - 1;
  while (i < n && j >= 0) {
    if (a[i][j] == k) {
      return true;
    } else if (a[i][j] > k) {
      j--;
    } else {
      i++;
    }
  }

  return false;
}

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> array = {{1, 4, 7, 11, 15},
                                         {2, 5, 8, 12, 19},
                                         {3, 6, 9, 16, 22},
                                         {10, 13, 14, 17, 24},
                                         {18, 21, 23, 26, 30}};
  int target = 5;
  return 0;
}
