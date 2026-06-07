#include <iostream>

int main(int argc, char *argv[]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      std::cout << "*";
    }
    std::cout << "\n";
  }
  return 0;
}
