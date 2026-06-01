#include <iostream>

int main(int argc, char *argv[]) {
  int n = 5;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      std::cout << "*";
    }
    std::cout << "\n";
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = n - i - 1; j > 0; j--) {
      std::cout << "*";
    }
    std::cout << "\n";
  }
  return 0;
}
