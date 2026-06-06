#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  std::string s = "abcdabejc";

  // pre-compute
  int hash[26] = {0};
  for (char c : s) {
    hash[c - 'a'] += 1;
  }

  for (char c : s) {
    std::cout << c << ": " << hash[c - 'a'] << std::endl;
  }
  return 0;
}
