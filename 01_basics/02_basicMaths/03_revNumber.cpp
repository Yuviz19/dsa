#include <iostream>

int revNum(int n) {
  int rev = 0;

  while (n != 0) {
    int lastDigit = n % 10;
    rev = (rev * 10) + lastDigit;
    n /= 10;
  }

  return rev;
}

int main(int argc, char *argv[]) {
  int n = 4554;
  std::cout << "Reverse for " << n << " is " << revNum(n) << std::endl;
  return 0;
}
