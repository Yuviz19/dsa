#include <iostream>
#include <string>

// let printing happens n = 10 times
void nTimes(int n, std::string s) {
  if (n == 10) {
    return;
  }
  std::cout << s << "\n";
  n++;
  nTimes(n, s);
}

int main(int argc, char *argv[]) {
  std::string str = "Void";
  int num = 0;

  nTimes(num, str);
  return 0;
}
