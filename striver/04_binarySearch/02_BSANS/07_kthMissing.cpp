// find the kth missing number from the sorted increasing array
#include <algorithm>
#include <map>
#include <vector>

int brute(std::vector<int> &v, int k) {
  std::map<int, int> map;
  int max = *std::max_element(v.begin(), v.end());

  for (auto i : v) {
    map[i]++;
  }

  std::vector<int> missing;
  for (int i = 1; i <= max + k; i++) {
    if (map[i] == 0) {
      missing.push_back(i);
    }
  }

  return missing[k - 1];
}

// would recommend to watch the vid again
int findKthPositive(std::vector<int> &arr, int k) {
  int n = arr.size();
  if (n == 0)
    return k;
  // find the missing number using binary search

  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    // missing number at mid
    int missing = arr[mid] - (mid + 1);
    if (missing < k)
      low = mid + 1;
    else
      high = mid - 1;
  }

  return low + k;
  // can also 'return high + 1 + k'
}

int bruteByStriver(std::vector<int> &v, int k) {

  for (int i = 0; i < v.size(); i++) {
    if (v[i] <= k)
      k++;
    else
      break;
  }

  return k;
}

int main(int argc, char *argv[]) {
  std::vector<int> vec = {2, 3, 4, 7, 11};
  int k = 5;
  // array pf missing numbers 1, 5, 6, 8, 9 and 5th is 9
  // should result to 9;
  return 0;
}
