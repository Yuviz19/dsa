// given a positive integer n
// determine wheather n is divisible by the sum of the following
// 1. sum of its digits
// 2. product of it's digits

int getSum(int n) {
  int sum = 0;
  while (n > 0) {
    sum += (n % 10);
    n /= 10;
  }
  return sum;
}

int getProd(int n) {
  long long prod = 1;
  while (n > 0) {
    prod *= 1LL * (n % 10);
    n /= 10;
  }

  return (int)prod;
}

bool checkDivisibility(int &n) {
  int sum = getSum(n);
  int prod = getProd(n);

  if (n % (sum + prod) == 0)
    return true;
  return false;
}

int main(int argc, char *argv[]) {
  int n = 99;
  // true
  // (9+9 = 18)
  // (9*9 = 81)
  // sum to 99 hence divisible
  return 0;
}
