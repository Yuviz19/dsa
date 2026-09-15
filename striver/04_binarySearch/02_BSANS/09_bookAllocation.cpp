// allocate books to m students such that the max number of pages allocated to a
// student is minimum if not possible, return false

#include <algorithm>
#include <vector>

long long allPages(std::vector<int> &a) {
  int n = a.size();
  long long sum = 0;
  for (int j = 0; j < n; j++) {
    sum += a[j];
  }

  return sum;
}

bool isPossible(std::vector<int> &a, int s, int i) {
  // asks if the i number of pages to single student is possible or not
  // of if it exceeds the number of students or not
  int n = a.size();
  int count = 1;
  int sum = 0;

  for (int k = 0; k < n; k++) {
    if ((sum + a[k]) <= i) {
      sum += a[k];
    } else {
      count++;
      sum = a[k];
    }

    if (count > s) {
      return false;
    }
  }

  return true;
}

long long optimal(std::vector<int> &a, int s) {
  int n = a.size();
  int low = *std::min_element(a.begin(), a.end());
  int high = allPages(a);

  long long ans = 0;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (isPossible(a, s, mid)) {
      low = mid + 1;
      ans = mid;
    } else {
      high = mid - 1;
    }
  }

  return ans;
}

long long brute(std::vector<int> &a, int s) {
  int n = a.size();
  int low = *std::min_element(a.begin(), a.end());
  int high = allPages(a);
  long long ans = 0;

  for (int i = low; i <= high; i++) {
    if (!isPossible(a, s, i)) {
      break;
    }

    ans = i;
  }

  return ans;
}

int main(int argc, char *argv[]) {
  std::vector<int> books = {12, 34, 67, 90};
  return 0;
}
