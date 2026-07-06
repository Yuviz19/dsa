// given an integer array and a target k
// return 1 (true) if if any 2 numbers have the sum k else 0 (false)
// or return the indices of the elements

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

int brute(std::vector<int> &a, int target) {
  // a two loop approach
  for (int i = 0; i < a.size() - 1; i++) {
    for (int j = i + 1; j < a.size(); j++) {
      if ((a[i] + a[j]) == target) {
        return 1;
      }
    }
  }

  return 0;
}

std::vector<int> better(std::vector<int> &a, int target) {
  // using a hash map approach and returning the index
  std::unordered_map<int, int> mp;
  for (int i = 0; i < a.size(); i++) {
    int complement = (target - a[i]);
    if (mp.find(complement) != mp.end()) {
      return {mp[complement], i};
    }
    mp[a[i]] = i;
  }
  return {-1, -1};
}

std::vector<int> optimal(std::vector<int> &a, int target) {
  // using two pointer approach with returning the indices

  std::vector<std::pair<int, int>> pair_array;
  for (int i = 0; i < a.size(); i++) {
    pair_array.push_back({a[i], i});
  }

  std::sort(pair_array.begin(), pair_array.end());

  int left = 0, right = a.size() - 1;
  while (left < right) {
    int sum = pair_array[left].first + pair_array[right].first;
    if (sum == target) {
      return {pair_array[left].second, pair_array[right].second};
    } else if (sum < target) {
      left++;
    } else {
      right--;
    }
  }
  return {-1, -1};
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {2, 6, 5, 8, 11};
  int target = 11;

  return 0;
}
