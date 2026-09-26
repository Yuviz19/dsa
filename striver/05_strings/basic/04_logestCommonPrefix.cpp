// given an array of strings
// to fins the longest common prefix

#include <string>
#include <vector>

std::string longestCommonPrefix(std::vector<std::string> &strs) {
  int n = strs.size();
  std::string prefix = strs[0];

  for (int i = 1; i < n; i++) {
    int j = 0;

    while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
      j++;
    }

    prefix = prefix.substr(0, j);
  }

  return prefix;
}

int main(int argc, char *argv[]) {
  std::vector<std::string> strs = {"flower", "flow", "flight"};
  return 0;
}
