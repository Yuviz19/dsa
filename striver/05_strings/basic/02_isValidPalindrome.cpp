// check if a phrace is a palindrome or not

#include <cctype>
#include <string>

bool isPalidrome(std::string s) {
  int i = 0, j = s.size() - 1;

  while (i <= j) {
    while (i <= j && !std::isalnum(s[i])) {
      i++;
    }

    while (i <= j && !std::isalnum(s[j])) {
      j--;
    }

    if (std::tolower(s[i]) != tolower(s[j])) {
      return false;
    }

    i++;
    j--;
  }

  return true;
}

int main(int argc, char *argv[]) {
  std::string str = "A man, a plan, a canal: Panama";
  return 0;
}
