#include <iostream>

int main(int argc, char *argv[]) {
  int n = 5;
  for (int i = 0; i < n; i++) {
    for (char j = 'E' - i; j <= 'E'; j++) {
      std::cout << j;
    }
    std::cout << "\n";
  }
  return 0;
}
