// Given an array of intervals where intervals[i] = [starti, endi],
// merge all overlapping intervals and return an array of the non-overlapping
// intervals that cover all the intervals in the input. Input :
// intervals=[[1,3],[2,6],[8,10],[15,18]] Output : [[1,6],[8,10],[15,18]]

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> merging(std::vector<std::vector<int>> &a) {
  if (a.empty())
    return {};

  std::vector<std::vector<int>> finalInt;

  // get the starting point
  std::sort(a.begin(), a.end());
  finalInt.push_back(a[0]);
  int currentEnd = a[0][1];

  for (int i = 1; i < a.size(); i++) {
    // next interval ends before the current
    if (currentEnd > a[i][1])
      continue;

    // making intervals overlap
    if (currentEnd >= a[i][0]) {
      currentEnd = a[i][1];

      finalInt.back()[1] = a[i][1];
    } else {
      finalInt.push_back(a[i]);
      currentEnd = a[i][1];
    }
  }

  return finalInt;
}

int main(int argc, char *argv[]) {
  std::vector<std::vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  std::vector<std::vector<int>> ans = merging(intervals);
  for (auto i : ans) {
    std::cout << i[0] << " " << i[1] << "\n";
  }
  return 0;
}
