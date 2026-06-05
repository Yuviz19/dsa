#include <iostream>

// let counting to 50
void counting(int n) {
  if (n == 0) {
    return;
  }
  std::cout << n << "\n";
  counting(n - 1);
}

int main(int argc, char *argv[]) {
  int num = 50;
  counting(num);
  return 0;
}
