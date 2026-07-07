// majority element that occurs more than N/2 times

#include <iostream>
#include <unordered_map>
#include <vector>

int majorityElement(std::vector<int> &a) {
  int halfArraySize = a.size() / 2;
  std::unordered_map<int, int> mp;

  for (auto num : a) {
    mp[num]++;
  }

  for (auto i : mp) {
    if (i.second > halfArraySize) {
      return i.first;
    }
  }

  return -1; // if none found
}

int mooresAlgo(std::vector<int> &a) {
  if (a.empty())
    return -1;
  int el, cnt = 0;
  for (int i = 0; i < a.size(); i++) {
    if (cnt == 0) {
      el = a[i];
      cnt = 1;
    } else if (el == a[i]) {
      cnt++;
    } else {
      cnt--;
    }
  }
  // now if a majorityElement exists, it will be el or no one else
  int elCount = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == el) {
      elCount++;
    }
  }

  if (elCount > (a.size() / 2)) {
    return el;
  }

  return -1;
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {7, 0, 0, 1, 7, 7, 2, 7, 7};
  int ans = majorityElement(arr);
  std::cout << ans << '\n';
  return 0;
}
