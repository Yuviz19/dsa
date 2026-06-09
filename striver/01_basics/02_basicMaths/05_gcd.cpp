#include <iostream>

int findGCD(int a, int b) {
  if (a == 0)
    return b;
  if (b == 0)
    return a;
  while (a > 0 && b > 0) {
    if (a > b) {
      a = a % b;
    } else {
      b = b % a;
    }

    if (a == 0)
      return b;
    if (b == 0)
      return a;
  }
}

int main(int argc, char *argv[]) {
  int gcd = findGCD(20, 15);
  std::cout << "GCD " << gcd;
  return 0;
}
