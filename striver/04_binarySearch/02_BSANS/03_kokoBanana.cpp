// return the minimum integer k, such that Koko can eat all bananas within h
// hours what is given -> n piles with 'ith' pile has ‘a[i]’ bananas,
// and 'h' hours which is the max limit

#include <algorithm>
#include <cmath>
#include <vector>

// brute force
int brute(std::vector<int> &p, int h) {
  int n = p.size();
  int m = *std::max_element(p.begin(), p.end());
  int ans = m;

  int i = 1;
  // what i represents here is the number of bananas koko can eat per hour
  while (i <= m) {
    int hr = 0;
    for (int j = 0; j < n; j++) {
      hr += ((p[j] + i - 1) / i);
    }
    if (hr <= h)
      return i;
    i++;
  }

  return ans;
}

int calculateTotalHours(std::vector<int> &piles, int speed) {
  int totalH = 0;
  for (int bananas : piles) {
    totalH += std::ceil((double)bananas / speed);
  }
  return totalH;
}

// using binary search
int kokoBanana(std::vector<int> &piles, int h) {
  int m = *std::max_element(piles.begin(), piles.end());
  int low = 1, high = m;
  int ans = m;

  while (low <= high) {
    int mid = (low + high) / 2;
    int hr = calculateTotalHours(piles, m);
    if (hr <= h) {
      ans = piles[mid];
      high = mid - 1;
    } else
      low = mid + 1;
  }

  return ans;
}

int main(int argc, char *argv[]) {
  // N = 5, a[] = {25, 12, 8, 14, 19}, h = 5
  int n = 5;
  std::vector<int> piles = {25, 12, 8, 14, 19};
  int h = 5;
  return 0;
}
