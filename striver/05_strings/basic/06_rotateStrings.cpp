// given 2 strings, and we need to return true, only if
// s can become goal upon certain number of rotations

#include <string>

bool rotateString(std::string s, std::string goal) {
  if (s.length() != goal.length())
    return false;
  std::string newS = s + s;
  if (newS.find(goal) != std::string::npos) {
    return true;
  }

  return false;
}

int main(int argc, char *argv[]) {
  std::string s = "abcde";
  std::string goal = "cdeab";

  return 0;
}
