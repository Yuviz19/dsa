#include <algorithm>
#include <iostream>
#include <vector>

int find_missing(std::vector<int> &a) {
  int max_val = *std::max_element(a.begin(), a.end());
  std::vector<int> hashArray(max_val + 1, 0);

  for (int i = 0; i < a.size(); i++) {
    hashArray[a[i]]++;
  }

  for (int i = 1; i < hashArray.size(); i++) {
    if (hashArray[i] == 0) {
      return i;
    }
  }

  return -1;
}

// comments for range [1..n]
// this needs to be changed, if the given range is [1..n] with size n-1
int missingViaXOR(std::vector<int> &a) {
  int n = a.size(); // add +1 here
  int xor_sum = 0;
  // start this loop from 1
  for (int i = 0; i <= n; i++) {
    xor_sum ^= i;
  }

  for (int i : a) {
    xor_sum ^= i;
  }

  return xor_sum;
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {0, 2, 4, 5, 3, 7, 1};
  // int missingNumber = find_missing(arr);
  int missingNumber = missingViaXOR(arr);
  std::cout << "Missing Number: " << missingNumber << "\n";
  return 0;
}
