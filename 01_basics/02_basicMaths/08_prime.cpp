#include <cmath>
#include <iostream>

bool isPrime(int n) {
  for (int i = 2; i <= std::floor(std::sqrt(n)); i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  int num = 67;
  if (isPrime(num)) {
    std::cout << num << " is a prime number" << std::endl;
  } else {
    std::cout << num << " is not a prime" << std::endl;
  }
  return 0;
}
