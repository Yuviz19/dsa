// Given a Matrix,
// if an element is 0, then set it's it entire row and column to zero

#include <vector>

// somewhere to the power of 3
void brute(std::vector<std::vector<int>> &a) {
  int m = a.size();
  int n = a[0].size();

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 0) {
        // mark all the elements in the row to -1
        for (int col = 0; col < n; col++) {
          if (a[i][col] != 0)
            a[i][col] = -1;
        }

        // mark all the elements in the column to -1
        for (int row = 0; row < m; row++) {
          if (a[row][j] != 0)
            a[row][j] = -1;
        }
      }
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == -1)
        a[i][j] = 0;
    }
  }
}

// near to the power of 2 and space O(n + m)
void better(std::vector<std::vector<int>> &a) {
  int m = a.size();
  int n = a[0].size();

  std::vector<int>
      row; // rather than doing this, make it something like a hash array
  std::vector<int> col; // and don't increment, rather make it one everytime

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 0) {
        row.push_back(i);
        col.push_back(j);
      }
    }
  }

  for (auto i : row) {
    for (int x = 0; x < n; x++) {
      a[i][x] = 0;
    }
  }
  for (auto j : col) {
    for (int y = 0; y < m; y++) {
      a[y][j] = 0;
    }
  }
}

// the traversal times can not be reduced
// hence, reducing the space complexity
void optimal(std::vector<std::vector<int>> &a) {
  int m = a.size();
  int n = a[0].size();
  int col0 = 1;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == 0) {
        a[i][0] = 0;
        if (j != 0)
          a[0][j] = 0;
        else
          col0 = 0;
      }
    }
  }

  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (a[i][j] != 0) {
        // check for the row and column
        if (a[i][0] == 0 || a[0][j] == 0) {
          a[i][j] = 0;
        }
      }
    }
  }

  if (a[0][0] == 0) {
    for (int i = 0; i < n; i++)
      a[0][i] = 0;
  }

  if (col0 == 0)
    for (int i = 0; i < m; i++)
      a[i][0] = 0;
}

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  return 0;
}
