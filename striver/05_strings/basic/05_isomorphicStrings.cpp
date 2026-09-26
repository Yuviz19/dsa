// Two strings s and t are isomorphic if the characters in s can be replaced to
// get t. note - that this mapping should be done from both the directions

#include <string>
#include <unordered_map>

bool isIsomorphic(std::string s, std::string t) {
  int n = s.size(); // same size as t
  std::unordered_map<char, char> mp1;
  std::unordered_map<char, char> mp2;

  for (int i = 0; i < n; i++) {
    // if the element exists and does not matches the char in other string
    if (mp1.count(s[i]) && mp1[s[i]] != t[i])
      return false;

    if (mp2.count(t[i]) && mp2[t[i]] != s[i])
      return false;

    mp1[s[i]] = t[i];
    mp2[t[i]] = s[i];
  }

  return true;
}

int main(int argc, char *argv[]) {
  std::string s = "egg";
  std::string t = "add";

  return 0;
}
