#include <iostream>

// let counting to 50
void counting(int n) {
  if (n == 0) {
    return;
  }
  counting(n - 1);
  std::cout << n << "\n";
}

int main(int argc, char *argv[]) {
  int num = 50;
  counting(num);
  return 0;
}
