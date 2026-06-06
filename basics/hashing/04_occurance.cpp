#include <algorithm>
#include <iostream>
#include <map>

int main(int argc, char *argv[]) {
  std::map<int, int> mp;
  int arr[] = {10, 5, 10, 15, 10, 5};
  for (int i : arr) {
    mp[i]++;
  }
  auto max_occur = std::max_element(
      mp.begin(), mp.end(),
      [](const auto &p1, const auto &p2) { return p1.second < p2.second; });

  auto min_occur = std::min_element(
      mp.begin(), mp.end(),
      [](const auto &p1, const auto &p2) { return p1.second < p2.second; });

  std::cout << "Max Occured: " << max_occur->first << "\n";
  std::cout << "Least Occured: " << min_occur->first << "\n";
  return 0;
}
