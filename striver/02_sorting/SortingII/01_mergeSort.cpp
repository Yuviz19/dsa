#include <iostream>
#include <vector>

void merge(std::vector<int> &a, int low, int mid, int high) {
  std::vector<int> temp;
  int left = low, right = mid + 1;

  while (left <= mid && right <= high) {
    if (a[left] <= a[right]) {
      temp.push_back(a[left++]);
    } else {
      temp.push_back(a[right++]);
    }
  }

  while (left <= mid) {
    temp.push_back(a[left++]);
  }
  while (right <= high) {
    temp.push_back(a[right++]);
  }

  for (int i = low; i <= high; i++) {
    a[i] = temp[i - low];
  }
}

void mergerSort(std::vector<int> &a, int low, int high) {
  if (low >= high)
    return;

  int mid = (low + high) / 2;
  mergerSort(a, low, mid);
  mergerSort(a, mid + 1, high);
  merge(a, low, mid, high);
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {4, 2, 7, 1, 5, 3};
  int arrSize = arr.size();

  mergerSort(arr, 0, arrSize - 1);

  for (int i : arr) {
    std::cout << i << " ";
  }

  return 0;
}
