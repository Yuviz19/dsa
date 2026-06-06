#include <iostream>

// size of array - 5
// array - 1 3 2 1 3
// number of queries - 5
// 1, 4, 2, 3, 12 - query elements

int main(int argc, char *argv[]) {
  // initialize array
  int n;
  std::cin >> n;
  int arr[n];

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  // precompute
  int hash[13] = {0};
  for (int i = 0; i < n; i++) {
    hash[arr[i]] += 1;
  }

  // fetch
  int q;
  std::cin >> q;
  while (q--) {
    int number;
    std::cin >> number;
    std::cout << hash[number];
  }
  return 0;
}
