#include <iostream>

int main(int argc, char *argv[]) {
  int n = 5;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= i; j++) {
      std::cout << j;
    }
    for (int k = 0; k < 2 * (n - 1) - (2 * i); k++) {
      std::cout << " ";
    }
    for (int l = i; l >= 1; l--) {
      std::cout << l;
    }
    std::cout << "\n";
  }
  return 0;
}
