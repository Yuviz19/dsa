// given an array, WAP to return a list of each unique triplets, (in any order)
// whose sum results to 0 (i != j != k)

#include <algorithm>
#include <set>
#include <vector>

// brute force -> using three statandard nested loops
// and each pointer starts at the next to the previous
// comp -> O(n^3) and space -> O(n)
std::vector<std::vector<int>> brute(std::vector<int> &a) {
  int n = a.size();
  std::set<std::vector<int>> st;

  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      for (int k = j; k < n; k++) {
        if (a[i] + a[j] + a[k]) {
          std::vector<int> temp = {a[i], a[j], a[k]};
          std::sort(temp.begin(), temp.end());
          st.insert(temp);
        }
      }
    }
  }

  std::vector<std::vector<int>> ans(st.begin(), st.end());
  return ans;
}

// better approach
// to get rid of the third loop, a[k] has to be - (a[i] + a[j])
// hence we can use hashing
std::vector<std::vector<int>> better(std::vector<int> &a) {
  // tha hashing can not be implemented directly, as it can create a chance for
  // duplication
  int n = a.size();
  std::set<std::vector<int>> st;

  for (int i = 0; i < n; i++) {
    std::set<int> hashSet;

    for (int j = i + 1; j < n; j++) {
      int rem = -(a[i] + a[j]);
      if (hashSet.find(rem) != hashSet.end()) {
        std::vector<int> temp = {a[i], a[j], rem};
        std::sort(temp.begin(), temp.end());
        st.insert(temp);
      }

      hashSet.insert(a[j]);
    }
  }

  std::vector<std::vector<int>> ans(st.begin(), st.end());
  return ans;
}
// time comp
// two loops -> O(n^2) and each time log n for set lookup and insertion
// so O(n^2logn) -> gives TLE on leetcode

// doing the reverse (to avoid using the set ds)
std::vector<std::vector<int>> Optimal(std::vector<int> &a) {
  std::vector<std::vector<int>> ans;
  std::sort(a.begin(), a.end());

  for (int i = 0; i < a.size(); i++) {
    if (i > 0 && a[i] == a[i - 1])
      continue;
    int j = i + 1;
    int k = a.size() - 1;

    while (j < k) {
      int sum = a[i] + a[j] + a[k];
      if (sum < 0) {
        j++;
      } else if (sum > 0) {
        k--;
      } else {
        std::vector<int> temp = {a[i], a[j], a[k]};
        ans.push_back(temp);
        j++;
        k--;
        while (j < k && a[j] == a[j - 1])
          j++;
        while (j < k && a[k] == a[k + 1])
          k--;
      }
    }
  }

  return ans;
}

int main(int argc, char *argv[]) {
  std::vector<int> array = {-1, 0, 1, 2, -1, -4};
  return 0;
}
