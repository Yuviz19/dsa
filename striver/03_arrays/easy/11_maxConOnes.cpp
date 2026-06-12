#include <algorithm>
#include <iostream>
#include <vector>

int maxConsOnes(std::vector<int> &a) {
  // count of number of ones
  int cnt = 0;
  // stores max streak of 1s
  int maxi = 0;
  for (int i : a) {
    if (i == 1) {
      cnt++;
      maxi = std::max(cnt, maxi);
    } else if (i == 0) {
      cnt = 0;
    }
  }

  return maxi;
}

int main(int argc, char *argv[]) {
  std::vector<int> binArr = {1, 0, 1, 1, 0, 1};
  std::cout << maxConsOnes(binArr);
  return 0;
}
