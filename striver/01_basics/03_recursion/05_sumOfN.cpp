#include <iostream>

// let sum till 50
int sumOfN(int n, int s) {
  if (n == 0)
    return s;
  s += n;
  return sumOfN((n - 1), s);
}

int main(int argc, char *argv[]) {
  int num = 50;
  int sum = 0;
  int finalSum = sumOfN(num, sum);
  std::cout << "Sum first " << num << " is " << finalSum << "\n";
  return 0;
}
