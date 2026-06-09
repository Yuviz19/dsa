#include <iostream>

// factorial till 10 -  3628800
int factorial(int n) {
  if (n == 0)
    return 1;
  return n * factorial(n - 1);
}

int main(int argc, char *argv[]) {
  int num = 10;
  int fact = factorial(num);

  std::cout << "factorial of " << num << " is " << fact << "\n";
  return 0;
}
