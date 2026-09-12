// find the kth missing number from the sorted increasing array
#include <vector>

// brute force method
int brute(std::vector<int> &arr, int k) {
  int ans = k;
  for (int i = 0; i < arr.size(); i++) {
    if (arr[i] <= k) {
      k++;
    } else
      break;
  }

  return ans;
}

// using binary search
int optimal(std::vector<int> &arr, int k) {
  int low = 0, high = arr.size() - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    int missingAtMid = arr[mid] - (mid + 1);

    if (missingAtMid < k) {
      low = mid + 1;
    } else
      high = mid - 1;
  }

  return (k + high + 1);
}

int main(int argc, char *argv[]) {
  std::vector<int> vec = {2, 3, 4, 7, 11};
  int k = 5;
  // array pf missing numbers 1, 5, 6, 8, 9 and 5th is 9
  // should result to 9;
  return 0;
}
