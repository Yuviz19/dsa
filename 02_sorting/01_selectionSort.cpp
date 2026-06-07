#include <array>
#include <iostream>

void selectionSort(int n, std::array<int, 6> arr) {
  for (int i = 0; i < n - 1; i++) {
    // assume that the current index holds the min element
    int mini = i;

    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[mini]) {
        mini = j;
      }
    }

    int temp = arr[mini];
    arr[mini] = arr[i];
    arr[i] = temp;
  }

  // print the remaining array
  std::cout << "New Array: ";
  for (int i : arr) {
    std::cout << i << " ";
  }
  std::cout << "\n";
}

int main(int argc, char *argv[]) {
  std::array<int, 6> arr = {13, 46, 24, 52, 20, 9};
  int n = arr.size();

  std::cout << "Initial Array: ";
  for (int i : arr) {
    std::cout << i << " ";
  }
  std::cout << "\n";

  selectionSort(n, arr);

  return 0;
}
