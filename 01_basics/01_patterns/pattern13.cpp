#include <iostream>

int main(int argc, char *argv[]) {
  int n = 5;
  int counter = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      counter++;
      std::cout << counter;
    }
    std::cout << "\n";
  }
  return 0;
}
