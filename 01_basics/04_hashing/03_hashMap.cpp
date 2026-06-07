#include <iostream>
#include <map>

int main(int argc, char *argv[]) {
  // array initialization
  int n;
  std::cout << "Enter number of Elements in array: ";
  std::cin >> n;
  int arr[n];
  std::cout << "\nEnter Array elements: \n";
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  // pre-compute
  std::map<int, int> mp;
  for (int i = 0; i < n; i++) {
    mp[arr[i]]++;
  }

  // queries
  int q;
  std::cout << "Enter number of queries: ";
  std::cin >> q;
  std::cout << "\nEnter the query elements: ";
  while (q--) {
    int num;
    std::cin >> num;
    // fetch
    std::cout << num << ": " << mp[num] << "\n";
  }

  return 0;
}
