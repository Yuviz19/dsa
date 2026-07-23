// Complete the function that accepts a string parameter, and reverses each word
// in the string. All spaces in the string should be retained.

#include <algorithm>
// #include <iostream>
#include <iostream>
#include <string>

std::string reverseWords(std::string str) {
  int currentIndex = 0, lastChanged = 0;
  for (auto i : str) {
    if (i == ' ') {
      std::reverse(str.begin() + lastChanged, str.begin() + currentIndex);
      lastChanged = currentIndex + 1;
    }
    currentIndex++;
  }

  // change the last word too
  std::reverse(str.begin() + lastChanged, str.end());

  return str;
}

int main(int argc, char *argv[]) {
  std::string str = "Hello world to all";
  std::cout << reverseWords(str);
  return 0;
}
