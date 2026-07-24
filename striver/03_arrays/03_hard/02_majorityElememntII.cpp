// Given an integer array of size n,
// find all elements that appear more than ⌊n / 3⌋ times.

#include <climits>
#include <unordered_map>
#include <vector>

// brute force is simply to traverse through the array and find the elements
// that have frequency more than n/3 a two loop approach

// better (using a hashmap) (single iteration)
// time -> O(n) and space -> O(2n)
std::vector<int> better(std::vector<int> &a) {
  std::unordered_map<int, int> freq;
  std::vector<int> ans;

  for (auto i : a) {
    freq[i]++;
    if (freq[i] == ((a.size() / 3) + 1)) {
      ans.push_back(i);
      break;
    }
  }

  return ans;
}

// Optimal -> using something like Moore's Voting algo
// aka extended Moore's Algo
std::vector<int> optimal(std::vector<int> &a) {
  std::vector<int> ans;
  int cnt1 = 0, cnt2 = 0;
  int el1 = INT_MIN, el2 = INT_MIN;

  for (int i = 0; i < a.size(); i++) {
    // if both are zero
    if (cnt1 == 0 && el2 != a[i]) {
      cnt1 = 1;
      el1 = a[i];
    } else if (cnt2 == 0 && el1 != a[i]) {
      cnt2 = 1;
      el2 = a[i];
    }
    // if the element mathces
    else if (el1 == a[i]) {
      cnt1++;
    } else if (el2 == a[i]) {
      cnt2++;
    } else {
      cnt1--;
      cnt2--;
    }
  }

  cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < a.size(); i++) {
    if (el1 == a[i])
      cnt1++;
    if (el2 == a[i])
      cnt2++;
  }
  if (cnt1 > (a.size() / 3))
    ans.push_back(el1);
  if (cnt2 > (a.size() / 3))
    ans.push_back(el2);

  return ans;
}

int main(int argc, char *argv[]) {
  std::vector<int> input = {1, 2, 1, 1, 3, 2};
  return 0;
}
