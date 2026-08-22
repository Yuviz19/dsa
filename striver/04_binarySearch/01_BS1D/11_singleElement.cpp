// given a sorted array of N integers, where
// every number appears twice. except one, find that element

#include <iostream>
#include <unordered_map>
#include <vector>

// brute method
int brute(std::vector<int> &a) {
  if (a.size() == 1)
    return a[0];

  for (int i = 0; i < a.size(); i++) {
    if (i == 0) {
      if (a[i] != a[i + 1])
        return a[i];
    } else if (i == a.size() - 1) {
      if (a[i] != a[i - 1])
        return a[i];
    } else {
      if (a[i] != a[i - 1] && a[i] != a[i + 1])
        return a[i];
    }
  }

  // dummy return
  return -1;
}

// another solution could be using a hashmap
int bruteHash(std::vector<int> &a) {
  std::unordered_map<int, int> map;
  for (int i = 0; i < a.size(); i++) {
    map[a[i]]++;
  }

  for (auto it : map) {
    if (it.second == 1)
      return it.first;
  }

  // dummy return
  return -1;
}

// using binery search
int singleBinary(std::vector<int> &a) {
  int n = a.size();
  int low = 1, high = n - 2;

  if (n == 1)
    return a[0];
  if (a[0] != a[1])
    return a[0];
  if (a[n - 1] != a[n - 2])
    return a[n - 1];

  while (low <= high) {
    int mid = (low + high) / 2;
    if (a[mid] != a[mid - 1] && a[mid] != a[mid + 1])
      return a[mid];

    if ((mid % 2 == 1 && a[mid] == a[mid - 1]) ||
        (mid % 2 == 0 && a[mid] == a[mid + 1]))
      low = mid + 1;
    if ((mid % 2 == 1 && a[mid] == a[mid + 1]) ||
        (mid % 2 == 0 && a[mid] == a[mid - 1]))
      high = mid - 1;
  }

  // dummy return
  return -1;
}

int main(int argc, char *argv[]) {
  std::vector<int> array = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
  // output -> 4
  std::cout << brute(array);
  return 0;
}
