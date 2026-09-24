// write a function to return a string
// the input is a string array, reverse it

#include <utility>
#include <vector>

void reverseString(std::vector<char> &s) {
  int i = 0, j = s.size() - 1;

  while (i <= j) {
    std::swap(s[i], s[j]);
    i++, j++;
  }
}

int main(int argc, char *argv[]) {
  std::vector<char> array = {'H', 'e', 'l', 'l', 'o'};
  return 0;
}
