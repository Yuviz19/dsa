// to find the target element in a 2D array
// given that the

#include <iostream>
#include <vector>

bool searchMatrix(std::vector<std::vector<int>> &a, int k) {
  int n = a.size(), m = a[0].size();
  int low = 0, high = (n * m) - 1;

  while (low <= high) {
    int mid = (low + high) / 2;
    int i = mid / m, j = mid % m; // i for row and j for colums

    if (a[i][j] == k) {
      return true;
    } else if (a[i][j] < k) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return false;
}

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> array = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  int target = 8;

  if (searchMatrix(array, target)) {
    std::cout << "Element Found";
  } else {
    std::cout << "Element not found";
  }

  return 0;
}
