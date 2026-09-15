// find the max possible minimum distance
#include <algorithm>
#include <vector>

bool isSufficient(std::vector<int> &a, int c, int i) {
  int n = a.size();
  int count = 1;
  int lastStall = a[0];

  for (int j = 1; j < n; j++) {
    if ((a[j] - lastStall) >= i) {
      lastStall = a[j];
      count++;
    }

    if (count == c)
      return true;
  }

  return false;
}

int optimal(std::vector<int> &a, int c) {
  int n = a.size();
  std::sort(a.begin(), a.end());
  int maxVal = a.back() - a.front();

  int low = 1, high = maxVal;
  int ans = 0;

  while (low <= high) {
    int mid = (low + high) / 2;
    bool isTrue = isSufficient(a, c, mid);

    if (isTrue) {
      low = mid + 1;
      ans = mid;
    } else {
      high = mid - 1;
    }
  }

  return ans;
}

int brute(std::vector<int> &a, int c) {
  // question gaurantees to provide at least 2 cows
  // returning the max possible minimum distance

  std::sort(a.begin(), a.end());
  int maxVal = a.back() - a.front();
  int ans = 0;

  for (int i = 1; i <= maxVal; i++) {
    bool suff = isSufficient(a, c, i);
    if (!suff) {
      break;
    }

    ans = i;
  }

  return ans;
}

int main(int argc, char *argv[]) {
  std::vector<int> stalls = {0, 3, 4, 7, 10, 9};
  return 0;
}
