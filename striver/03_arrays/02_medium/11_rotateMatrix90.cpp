// rotate a given matrix by 90

#include <algorithm>
#include <utility>
#include <vector>
// #include <iostream>

// the key observation is that, the columns of the original matrix become the
// rows for the new matrix but reversed
void brtue(std::vector<std::vector<int>> &a) {
  int m = a.size();    // number of rows
  int n = a[0].size(); // number of columns
  std::vector<std::vector<int>> nMat(m, std::vector<int>(n));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      nMat[i][n - j - 1] = a[j][i];
    }
  }

  a = nMat;
}

// note -> this method is only applicable for a square matrix
// otherwise the brute method works
void optimal(std::vector<std::vector<int>> &a) {
  int m = a.size();
  int n = a[0].size();

  // finding the transpose
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < n; j++) {
      std::swap(a[i][j], a[j][i]);
    }
  }

  // now reversing the rows
  for (int i = 0; i < m; i++) {
    std::reverse(a[i].begin(), a[i].end());
  }
}

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  return 0;
}
