#include <algorithm>
#include <climits>
#include <utility>
#include <vector>

// brute force method
// complexity -> near to O(n^2)
int brute(std::vector<int> &a) {
  int n = a.size();
  long long multiplication = a[0];
  for (int i = 0; i < n; i++) {
    long long currMul = 1;
    for (int j = i; j < n; j++) {
      currMul *= (1LL * a[j]);
      multiplication = std::max(currMul, multiplication);
    }
  }

  return multiplication;
}

// trying to return the indices where the subarray exists
std::pair<int, int> bruteIndices(std::vector<int> &a) {
  if (a.empty()) {
    return {-1, -1};
  }

  int n = a.size();
  long long multiplication = a[0];
  int start = 0, end = 0;

  for (int i = 0; i < n; i++) {
    long long currMul = 1;
    for (int j = i; j < n; j++) {
      currMul *= (1LL * a[j]);
      if (currMul > multiplication) {
        multiplication = currMul;
        end = j;
        start = i;
      }
    }
  }

  return {start, end};
}

int optimal(std::vector<int> &a) {
  int n = a.size();
  int max = INT_MIN;
  int prefix = 1, suffix = 1;

  for (int i = 0; i < n; i++) {
    if (prefix == 0)
      prefix = 1;
    if (suffix == 0)
      suffix = 1;

    prefix *= a[i];
    suffix *= a[n - i - 1];

    max = std::max(max, std::max(prefix, suffix));
  }

  return max;
}

int main(int argc, char *argv[]) {
  std::vector<int> array = {1, 2, -3, 0, -4, -5};
  return 0;
}
