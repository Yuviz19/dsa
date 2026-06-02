#include <algorithm>
#include <iostream>

int main(int argc, char *argv[]) {
  int n = 5;
  for (int i = 0; i < 2 * n - 1; i++) {
    for (int j = 0; j < 2 * n - 1; j++) {
      int top = i;
      int left = j;
      int bottom = 2 * (n - 1) - i;
      int right = 2 * (n - 1) - j;
      int distance = std::min(std::min(top, bottom), std::min(right, left));
      int value = n - distance;
      std::cout << value;
    }
    std::cout << "\n";
  }
  return 0;
}
