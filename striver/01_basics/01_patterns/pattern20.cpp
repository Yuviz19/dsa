#include <iostream>

int main(int argc, char *argv[]) {
  int n = 5;

  // up pattern
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

  // down pattern
  for (int i = 1; i < 5; i++) {
    for (int j = 5 - i; j > 0; j--) {
      std::cout << "*";
    }
    for (int k = 0; k < 2 * i; k++) {
      std::cout << " ";
    }
    for (int j = 5 - i; j > 0; j--) {
      std::cout << "*";
    }
    std::cout << "\n";
  }

  return 0;
}
