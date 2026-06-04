#include <cmath>
#include <iostream>
#include <set>

std::set<int> allDivisors(int n) {
  std::set<int> divisors;
  for (int i = 1; i <= std::floor(sqrt(n)); i++) {
    if (n % i == 0) {
      divisors.insert(i);
      divisors.insert((n / i));
    }
  }
  return divisors;
}

int main(int argc, char *argv[]) {
  int num = 36;
  std::set<int> divs = allDivisors(num);
  for (auto ele : divs) {
    std::cout << ele << " ";
  }
  return 0;
}
