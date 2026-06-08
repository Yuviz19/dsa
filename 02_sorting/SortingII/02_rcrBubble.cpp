#include <iostream>
#include <vector>

void rcrBubble(std::vector<int> &a, int last) {
  if (last == 0)
    return;
  for (int j = 0; j < last; j++) {
    if (a[j] > a[j + 1]) {
      std::swap(a[j], a[j + 1]);
    }
  }

  rcrBubble(a, --last);
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {13, 46, 24, 52, 20, 9};
  int arrSize = arr.size();

  rcrBubble(arr, arrSize - 1);

  for (int i : arr) {
    std::cout << i << " ";
  }
  return 0;
}
