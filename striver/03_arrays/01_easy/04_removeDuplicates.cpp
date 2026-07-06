#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int> &a) {
  if (a.empty())
    return 0;

  int i = 0;
  for (int j = 1; j < a.size(); j++) {
    if (a[i] != a[j]) {
      i++;
      a[i] = a[j];
    }
  }

  return i + 1;
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int uniqueIndex = removeDuplicates(arr);
  std::cout << "The size of unique array is: " << uniqueIndex << "\n";
  return 0;
}
