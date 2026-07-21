// given a matrix,
// print it in spiral order

#include <vector>
// #include <iostream>

// approach => right -> bottom -> left -> top
// time complexity -> O(n x m)
std::vector<int> spiral(std::vector<std::vector<int>> &a) {
  std::vector<int> result;
  int top = 0, bottom = a.size() - 1;
  int left = 0, right = a[0].size() - 1;

  while (top <= bottom && left <= right) {
    // right
    for (int i = left; i <= right; i++) {
      result.push_back(a[top][i]);
    }
    top++;

    // bottom
    for (int i = top; i <= bottom; i++) {
      result.push_back(a[i][right]);
    }
    right--;

    // left
    if (top <= bottom) {
      for (int i = right; i >= left; i--) {
        result.push_back(a[bottom][i]);
      }
      bottom--;
    }

    // top
    if (left <= right) {
      for (int i = bottom; i >= top; i--) {
        result.push_back(a[i][left]);
      }
      left++;
    }
  }

  return result;
}

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> matrix = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
  return 0;
}
