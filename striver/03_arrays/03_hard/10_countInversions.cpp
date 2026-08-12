// Count number of Inversions
// given an array of size N, return the count of pairs for which
// i,j where i < j and a[i] > a[j]

#include <vector>

// brute force
int brute(std::vector<int> &a) {
  int n = a.size();
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] > a[j])
        count++;
    }
  }
  return count;
}

// Optimal Solution using merge Sort

int cnt = 0;

void merge(std::vector<int> &a, int low, int mid, int high) {
  std::vector<int> temp;
  int left = low, right = mid + 1;

  while (left <= mid && right <= high) {
    if (a[left] <= a[right]) {
      temp.push_back(a[left++]);
    } else {
      cnt += (mid - left + 1);
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

int optimal(std::vector<int> &a) {
  mergerSort(a, 0, a.size() - 1);
  return cnt;
}

int main(int argc, char *argv[]) {
  std::vector<int> array = {5, 3, 2, 1, 4};
  return 0;
}
