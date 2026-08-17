// a binary search is a searching algo
// below are both the iterative and the recursive codes

#include <vector>

// Iterative code
// returning the index of the target element
int Iterative(std::vector<int> &a, int n, int target) {
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (a[mid] == target)
      return mid;
    else if (target > a[mid]) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return -1;
}

// recursive approach
// returning the index of the target element
int Recursion(std::vector<int> &a, int low, int high, int target) {
  if (low > high)
    return -1;
  int mid = (low + high) / 2;
  if (a[mid] == target)
    return mid;
  else if (a[mid] < target)
    return Recursion(a, low, mid - 1, target);
  else
    return Recursion(a, mid + 1, high, target);
}

// complexities ->
// O(log n) (in base 2)

// the Overflow case
// if the low or high are INT_MAX or INT_MIN respectively
// then there could be a case that due to division, they can Overflow
// a better way of writting mid can be
// mid = low + ((high - low) / 2) the prevents INT_MAX

int main(int argc, char *argv[]) {
  std::vector<int> array = {3, 4, 6, 7, 9, 12, 16, 17};
  int n = array.size();
  int target = 13;
  int iterativeResult = Iterative(array, n, target);
  int recursiveResult = Recursion(array, 0, n - 1, target);
  return 0;
}
