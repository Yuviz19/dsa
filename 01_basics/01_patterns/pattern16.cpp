#include <iostream>

int main(int argc, char *argv[]) {
  char n = 'F';
  for (char i = 'A'; i < n; i++) {
    for (char j = 'A'; j <= i; j++) {
      std::cout << i;
    }
    std::cout << "\n";
  }
  return 0;
}
