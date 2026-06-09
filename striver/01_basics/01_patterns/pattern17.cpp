#include <iostream>

int main(int argc, char *argv[]) {
  int n = 5;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      std::cout << " ";
    }

    char ch = 'A';
    int breakpoint = (2 * i + 1) / 2;
    for (int k = 1; k <= 2 * i + 1; k++) {
      std::cout << ch;
      if (k <= breakpoint)
        ch++;
      else
        ch--;
    }

    std::cout << "\n";
  }
  return 0;
}
