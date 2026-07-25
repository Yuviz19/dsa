// given an array of N integers, find unique quads that add up to given value
// return an array of nums[a], nums[b], nums[c] and nums[d] where a != b != c !=
// d

#include <algorithm>
#include <set>
#include <vector>

// a 4 loop approach
// and a set to store unique
std::vector<std::vector<int>> brute(std::vector<int> &nums, int t) {
  // this defo not getting accepted
  std::set<std::vector<int>> st;
  int n = nums.size();

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        for (int l = k + 1; k < n; l++) {
          if ((nums[i] + nums[j] + nums[k] + nums[l]) == t) {
            std::vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
            std::sort(temp.begin(), temp.end());
            st.insert(temp);
          }
        }
      }
    }
  }

  std::vector<std::vector<int>> ans(st.begin(), st.end());
  return ans;
}

// better -> a three loop approach
// and the last element being a remaining varaible
std::vector<std::vector<int>> better(std::vector<int> &nums, int t) {
  std::set<std::vector<int>> st;
  int n = nums.size();

  for (int i = 0; i < n; i++) {
    std::set<int> hashSet;
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        int rem = -(nums[i] + nums[j] + nums[k]);
        if (hashSet.find(rem) != hashSet.end()) {
          std::vector<int> temp = {nums[i], nums[j], nums[k], rem};
          std::sort(temp.begin(), temp.end());
          st.insert(temp);
        }
      }
    }
  }

  std::vector<std::vector<int>> ans(st.begin(), st.end());
  return ans;
}

// optimal -> a two loop and a 2 pointer approach (4 total pointers)
// i and j are the loops pointer and are fixed
// while k and l are moving and are similar to the 3sum approach
std::vector<std::vector<int>> optimal(std::vector<int> &nums, int t) {
  int n = nums.size();
  std::vector<std::vector<int>> ans;
  std::sort(nums.begin(), nums.end());

  for (int i = 0; i < n; i++) {
    if (i > 0 && nums[i] == nums[i - 1])
      continue;
    for (int j = i + 1; j < n; j++) {
      if (j > (i + 1) && nums[j] == nums[j - 1])
        continue;
      int k = j + 1, l = n - 1;
      while (k < l) {
        long long sum = 1LL * nums[i] + nums[j] + nums[k] + nums[l];
        if (sum == t) {
          ans.push_back({nums[i], nums[j], nums[k], nums[l]});
          k++;
          l--;
          while (k < l && nums[k] == nums[k - 1])
            k++;
          while (k < l && nums[l] == nums[l + 1])
            l--;
        } else if (sum < t) {
          k++;
        } else
          l--;
      }
    }
  }

  return ans;
}

int main(int argc, char *argv[]) {
  std::vector<int> array = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
  int target = 9;
  return 0;
}
