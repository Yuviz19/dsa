#include <algorithm>
#include <vector>

long long totalWt(std::vector<int> &w) {
  long long wt = 0;
  for (int i = 0; i < w.size(); i++) {
    wt += w[i];
  }

  return wt;
}

int findNumberDays(std::vector<int> &w, int wt) {
  int day = 1;
  int currentWt = 0;
  for (int i = 0; i < w.size(); i++) {
    if ((currentWt + w[i]) <= wt) {
      currentWt += w[i];
    } else {
      day++;
      currentWt = w[i];
    }
  }

  return day;
}

int shipWithinDays(std::vector<int> &weights, int days) {
  long long totalW = totalWt(weights);
  int minW = *std::max_element(weights.begin(), weights.end());
  int ans = 0;

  int low = minW;
  long long high = totalW;

  while (low <= high) {
    int mid = (low + high) / 2;
    int day = findNumberDays(weights, mid);
    if (day <= days) {
      high = mid - 1;
      ans = mid;
    } else
      low = mid + 1;
  }

  return ans;
}

int brute(std::vector<int> &w, int d) {
  long long totalW = totalWt(w);
  int minW = *std::max_element(w.begin(), w.end());
  int ans = 0;

  for (long long i = minW; i <= totalW; i++) {
    int day = findNumberDays(w, i);
    if (day <= d) {
      ans = i;
      break;
    }
  }

  return ans;
}

int main(int argc, char *argv[]) {
  std::vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
  int minDays = 5;
  return 0;
}
