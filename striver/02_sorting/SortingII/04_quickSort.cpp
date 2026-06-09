#include <algorithm>
#include <iostream>
#include <vector>

int partition(std::vector<int> &a, int low, int high) {
  int pivot = a[low];
  int i = low;
  int j = high;

  while (i < j) {
    while (a[i] <= pivot && i <= high - 1) {
      i++;
    }

    while (a[j] > pivot && j >= low + 1) {
      j++;
    }

    if (i < j)
      std::swap(a[i], a[j]);
  }

  std::swap(a[low], a[j]);
  return j;
}

void quickSort(std::vector<int> &a, int low, int high) {
  if (low < high) {
    int pIndex = partition(a, low, high);
    quickSort(a, low, pIndex - 1);
    quickSort(a, pIndex + 1, high);
  }
}

int main(int argc, char *argv[]) {
  // declare the array and call quickSort function
  return 0;
}
