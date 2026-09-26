// sort the character based on the frequency

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

std::string frequencySort(std::string s) {
  // using a map for auto sorting
  if (s.size() == 0) {
    return "";
  }

  std::string ans;

  // map the items
  std::unordered_map<char, int> mp;
  for (auto c : s) {
    mp[c]++;
  }

  // sort the string
  std::vector<std::pair<char, int>> freq(mp.begin(), mp.end());
  std::sort(freq.begin(), freq.end(),
            [](auto &a, auto &b) { return a.second > b.second; });

  // add the characters back
  for (auto &[c, count] : freq) {
    ans += std::string(count, c);
  }

  return ans;
}

int main(int argc, char *argv[]) {
  std::string s = "tree";
  return 0;
}
