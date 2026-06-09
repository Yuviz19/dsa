#include <algorithm>
#include <iostream>
#include <string>

void modifyString(std::string &s) {
  s.erase(std::remove(s.begin(), s.end(), ' '), s.end());
}

bool isPalindrome(int i, std::string &s) {
  if (i >= s.length() / 2)
    return true;
  if (s[i] != s[s.length() - 1 - i])
    return false;
  return isPalindrome(i + 1, s);
}

int main(int argc, char *argv[]) {
  std::string str = "race car";
  modifyString(str);
  bool stringPal = isPalindrome(0, str);

  if (stringPal) {
    std::cout << str << " is a Palindrome" << "\n";
  } else {
    std::cout << str << " is not a Palindrome" << "\n";
  }

  return 0;
}
