#include <iostream>

int main(int argc, char *argv[]) {
  int n = 5;

  // upward pattern
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      std::cout << "*";
    }
    for (int k = 0; k < i * 2; k++) {
      std::cout << " ";
    }
    for (int l = 0; l < n - i; l++) {
      std::cout << "*";
    }
    std::cout << "\n";
  }

  // downward pattern
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      std::cout << "*";
    }

    for (int k = 0; k < 2 * n - (2 * i); k++) {
      std::cout << " ";
    }
    for (int j = 0; j < i; j++) {
      std::cout << "*";
    }
    std::cout << "\n";
  }

  return 0;
}
