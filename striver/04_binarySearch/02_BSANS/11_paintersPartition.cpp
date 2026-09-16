// similar to the largest sum split
// painters partition

#include <algorithm>
#include <numeric>
#include <vector>

bool isValid(std::vector<int> &a, int k, int i) {
  int n = a.size();
  int count = 1;
  long long sum = 0;

  for (int j = 0; j < n; j++) {
    if (sum + a[j] < i) {
      sum += a[j];
    } else {
      count++;
      sum = a[j];
    }
  }

  if (count > k) {
    return false;
  }

  return true;
}

int painterPaetition(std::vector<int> &a, int k) {
  int n = a.size();
  if (n == 0) {
    return 0;
  }

  int low = *std::max_element(a.begin(), a.end());
  long long high = std::accumulate(a.begin(), a.end(), 0);
  long long ans = 0;

  while (low <= high) {
    long long mid = (low + high) / 2;
    if (isValid(a, k, mid)) {
      high = mid - 1;
      ans = mid;
    } else {
      low = high - 1;
    }
  }

  return ans;
}

int main(int argc, char *argv[]) {
  std::vector<int> array = {5, 5, 5, 5};
  int k = 2;
  return 0;
}
