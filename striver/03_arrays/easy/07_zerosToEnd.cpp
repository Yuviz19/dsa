#include <iostream>
#include <utility>
#include <vector>

void toEnd_brute(std::vector<int> &a) {
  std::vector<int> temp;
  int counter = 0;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] != 0)
      temp.push_back(a[i]);
    else
      ++counter;
  }
  for (int i = 0; i < counter; i++) {
    temp.push_back(0);
  }

  for (int i : temp) {
    std::cout << i << " ";
  }
}

void toEnd_optimal(std::vector<int> &a) {
  int j = -1;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == 0) {
      j = i;
      break;
    }
  }

  if (j == -1)
    return;
  for (int i = j + 1; i < a.size(); i++) {
    if (a[i] != 0) {
      std::swap(a[i], a[j]);
      j++;
    }
  }

  for (int i : a) {
    std::cout << i << " ";
  }
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {1, 0, 2, 3, 0, 4, 0, 1};
  // toEnd_brute(arr);
  toEnd_optimal(arr);
  return 0;
}
