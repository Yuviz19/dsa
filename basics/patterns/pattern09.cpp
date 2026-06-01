#include <iostream>

int main(int argc, char *argv[]) {
  int n = 5;

  // pattern 07
  for (int i = 0; i < 5; i++) {
    for (int j = n - i - 1; j > 0; j--) {
      std::cout << " ";
    }
    for (int k = 0; k < 2 * i + 1; k++) {
      std::cout << "*";
    }
    std::cout << "\n";
  }

  // pattern 08
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < i; j++) {
      std::cout << " ";
    }
    for (int k = 0; k < 2 * n - (2 * i + 1); k++) {
      std::cout << "*";
    }
    std::cout << "\n";
  }
  return 0;
}
