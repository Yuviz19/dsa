#include <iostream>

int main(int argc, char *argv[]) {
  int n = 5;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      if (i % 2 == 0 && j % 2 == 0) {
        std::cout << "1";
      } else if (i % 2 != 0 && j % 2 != 0) {
        std::cout << "1";
      } else {
        std::cout << "0";
      }
    }
    std::cout << "\n";
  }
  return 0;
}
