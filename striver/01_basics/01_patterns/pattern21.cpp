#include <iostream>

int main(int argc, char *argv[]) {
  int n = 4;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0 || i == 3 || j == 0 || j == 3) {
        std::cout << "*";
      } else
        std::cout << " ";
    }
    std::cout << "\n";
  }
  return 0;
}
