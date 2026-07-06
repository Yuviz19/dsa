#include <iostream>
#include <vector>

void rotateLeftOne(std::vector<int> &a) {
  int firstEle = a[0];
  for (int i = 1; i < a.size(); i++) {
    a[i - 1] = a[i];
  }
  a[a.size() - 1] = firstEle;
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {1, 2, 3, 4, 5};
  rotateLeftOne(arr);
  for (int i : arr) {
    std::cout << i << " ";
  }
  return 0;
}
