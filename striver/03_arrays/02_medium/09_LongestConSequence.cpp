// Given an array nums of n integers.
// Return the length of the longest sequence of consecutive integers.
// The integers in this sequence can appear in any order.

#include <algorithm>
#include <climits>
#include <unordered_set>
// #include <iostream>
#include <vector>

int brute(std::vector<int> &a) {
  // O(n^2)
  int longest = 1;

  for (int i = 0; i < a.size(); i++) {
    int x = a[i];
    int count = 1;

    while (std::binary_search(a.begin(), a.end(), (x + 1))) {
      x += 1;
      count++;
    }

    longest = std::max(longest, count);
  }

  return longest;
}

int better(std::vector<int> &a) {
  // effectively O(nlogn)

  if (a.empty()) {
    return 0;
  }

  std::sort(a.begin(), a.end()); // nlogn for sorting
  int lastSmallest = INT_MIN, longest = 1, count = 0;

  for (int i = 0; i < a.size(); i++) {
    if (lastSmallest == a[i]) {
      continue;
    } else if (lastSmallest + 1 != a[i]) {
      count = 1;
      lastSmallest = a[i];
    } else if (lastSmallest + 1 == a[i]) {
      lastSmallest = a[i];
      count++;
    }

    longest = std::max(longest, count);
  }

  return longest;
}

int optimal(std::vector<int> &a) {
  std::unordered_set<int> st;
  if (a.empty())
    return 0;
  int longest = 1;

  for (int i = 0; i < a.size(); i++) {
    st.insert(a[i]);
  }

  for (auto it : st) {
    if (st.find(it - 1) == st.end()) { // it's previous element does not exists
      int cnt = 1;
      int x = it;
      while (st.find(x + 1) != st.end()) {
        cnt++;
        x++;
      }

      longest = std::max(longest, cnt);
    }
  }

  return longest;
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {100, 4, 200, 1, 3, 2};
  return 0;
}
