// to find the second smallest and also the second largest element
#include <climits>
#include <iostream>
#include <vector>

int secondLargest(std::vector<int> a) {
  int max = a[0];

  for (int i = 0; i < a.size(); i++) {
    if (max < a[i])
      max = a[i];
  }

  int secMax = INT_MIN;
  for (int i = 0; i < a.size(); i++) {
    if (secMax < a[i] && a[i] != max)
      secMax = a[i];
  }

  return secMax;
}

int secondSmallest(std::vector<int> a) {
  int min = a[0];

  for (int i = 0; i < a.size(); i++) {
    if (min > a[i])
      min = a[i];
  }

  int secMin = INT_MAX;
  for (int i = 0; i < a.size(); i++) {
    if (secMin > a[i] && a[i] != min)
      secMin = a[i];
  }

  return secMin;
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {1, 2, 4, 7, 7, 5};

  int secLarge = secondLargest(arr);
  int secSmall = secondSmallest(arr);

  std::cout << "second largest element: " << secLarge << "\n";
  std::cout << "second smallest element: " << secSmall << "\n";
  return 0;
}
