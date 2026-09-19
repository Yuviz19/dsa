// minimise the max distance between gas stations
// given a sorted integer array of size n with a[i] being the coordinates of the
// n gas stations given k such that to insert k new statins between the given
// ones so that the max distance between then is minimum you are allowed to
// place the gas stations in decimal places too

#include <algorithm>
#include <queue>
#include <vector>

// you need to return the answer in long double or double
// so in these cases answers within 10^-6 of the actuall answers are accespted

// tc - O((n * k) + n)
long double brute(std::vector<int> &a, int k) {
  int n = a.size();
  std::vector<int> howMany(n - 1, 0);

  for (int i = 1; i <= k; i++) {
    long double maxValue = -1, maxInd = -1;

    for (int j = 0; j < n - 1; j++) {
      long double diff = a[j + 1] - a[j];
      long double sectionLen = (long double)diff / (howMany[j] + 1);

      if (maxValue < sectionLen) {
        maxValue = sectionLen;
        maxInd = j;
      }
    }

    howMany[maxInd]++;
  }

  long double maxAns = -1;
  for (int k = 0; k < n - 1; k++) {
    long double secLen = (long double)(a[k + 1] - a[k]) / (howMany[k] + 1);
    maxAns = std::max(maxAns, secLen);
  }

  return maxAns;
}

// using priority queue
// tc - O((n + k)logn)
// sc - O(n - 1)
long double better(std::vector<int> &a, int k) {
  int n = a.size();
  std::vector<int> howMany(n - 1, 0);
  std::priority_queue<std::pair<long double, int>> pq;

  for (int i = 0; i < n - 1; i++) {
    pq.push({a[i + 1] - a[i], i});
  }

  for (int i = 0; i <= k; i++) {
    auto tp = pq.top();
    pq.pop();
    int secInd = tp.second;
    howMany[secInd]++;

    int iniDiff = a[secInd + 1] - a[secInd];
    int newDiff = iniDiff / (howMany[secInd] + 1);
    pq.push({newDiff, secInd});
  }

  return pq.top().first;
}

long double largestPossible(std::vector<int> &a) {
  long double ans = -1;
  for (int i = 0; i < a.size() - 1; i++) {
    long double maxVal = (long double)(a[i + 1] - a[i]);
    ans = std::max(maxVal, ans);
  }

  return ans;
}

bool gasStationCount(std::vector<int> &a, int k, long double mid) {
  int cnt = 0;
  for (int i = 1; i < a.size(); i++) {
    int numberOfSections = ((a[i] - a[i - 1]) / mid);
    if (a[i] - a[i - 1] == numberOfSections * mid) {
      numberOfSections--;
    }
    cnt += numberOfSections;
  }

  if (cnt > k) {
    return false;
  }

  return true;
}

// using binary search
long double Optimal(std::vector<int> &a, int k) {
  int n = a.size();
  long double low = 0;
  long double high = largestPossible(a);
  long double ans = -1;

  while (high - low > 1e-6) {
    long double mid = (long double)((low + high) / 2);
    if (gasStationCount(a, k, mid)) {
      ans = mid;
      high = mid;
    } else
      low = mid;
  }

  return ans;
}

int main(int argc, char *argv[]) {
  std::vector<int> gasStations = {1, 2, 3, 4, 5};
  int k = 4;

  // std::cout << brute(gasStations, k);
  return 0;
}
