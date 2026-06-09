#include <iostream>

int fib(int n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  return fib(n - 1) + fib(n - 2);
}

int main(int argc, char *argv[]) {
  int n = 30;
  int fibSum = fib(n);
  std::cout << "Fibonacci Sum of " << n << " is " << fibSum << "\n";
  return 0;
}
