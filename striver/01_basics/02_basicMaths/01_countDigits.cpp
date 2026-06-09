#include <iostream>

// brute force (my approach)
int count(int &num) {
  int counter = 0;
  while (num > 0) {
    counter++;
    num /= 10;
  }
  return counter;
}

int main(int argc, char *argv[]) {
  int n = 12345;
  int digcount = count(n);
  std::cout << digcount << std::endl;
  return 0;
}
