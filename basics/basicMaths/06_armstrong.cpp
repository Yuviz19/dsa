#include <cmath>
#include <iostream>

bool isArmstrong(int n) {
  // size of number
  int originalNum = n;
  int nLenght = std::log10(n) + 1;
  int sum = 0;
  while (n != 0) {
    sum += std::pow((n % 10), nLenght);
    n /= 10;
  }
  return originalNum == sum;
}

int main(int argc, char *argv[]) {
  int num = 123;
  if (isArmstrong(num)) {
    std::cout << num << " is an Armstrong number" << std::endl;
  } else {
    std::cout << num << " is not an Armstrong number" << std::endl;
  }
  return 0;
}
