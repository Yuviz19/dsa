#include <cmath>
#include <iostream>

// optimal approach
int count(int &num) { return (std::log10(num) + 1); }

int main(int argc, char *argv[]) {
  int n = 12345;
  std::cout << count(n) << std::endl;
  return 0;
}
