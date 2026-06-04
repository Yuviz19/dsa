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
  int i = 2552;
  int revi = revNum(i);
  if (i == revi) {
    std::cout << "The number is a Palindrome" << std::endl;
  } else {
    std::cout << "The number is not a Palindrome" << std::endl;
  }

  return 0;
}
