#include <string>

std::string largestOddNumber(std::string num) {
  std::string ans;

  int j = num.size();
  for (int i = num.size() - 1; i >= 0; i--) {
    if ((num[i] - '0') % 2 == 1) {
      ans = num.substr(0, i);
      return ans;
    }
  }

  return "-1";
}

int main(int argc, char *argv[]) {
  std::string s = "35427";
  return 0;
}
