// to validate if two strings are anagram are not
// anagram -> word or phrase formed by rearranging the letters

#include <string>
#include <unordered_map>

bool isAnagram(std::string s, std::string t) {
  if (s.size() != t.size())
    return false;
  std::unordered_map<char, int> mp1;
  std::unordered_map<char, int> mp2;

  for (int i = 0; i < s.size(); i++) {
    mp1[s[i]]++;
  }

  for (int j = 0; j < t.size(); j++) {
    mp2[t[j]]++;
  }

  for (auto it : mp1) {
    if (it.second != mp2[it.first]) {
      return false;
    }
  }

  return true;
}

int main(int argc, char *argv[]) {
  std::string s = "anagram", t = "nagaram";
  return 0;
}
