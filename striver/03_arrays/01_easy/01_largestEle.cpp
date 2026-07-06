#include <iostream>
#include <vector>

int largestEle(std::vector<int> &a) {
  int n = a.size();
  int max = a[0];
  for (int i = 0; i < n; i++) {
    if (max < a[i])
      max = a[i];
  }
  return max;
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {2, 5, 1, 3, 0};
  int max = largestEle(arr);
  std::cout << "largest element is: " << max;
  return 0;
}
