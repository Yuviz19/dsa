// return the number of reverse pairs in the array
// reverse pairs are a pair where, for i and j
// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].

#include <vector>

// this does give time limit exceeded (TLE)
int brute(std::vector<int> &a) {
  int n = a.size();
  int count = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] > 2LL * a[j])
        count++;
    }
  }

  return count;
}

// optimal using merge sort
// will be done later
int optimal(std::vector<int> &a) {}

int main(int argc, char *argv[]) {
  std::vector<int> array = {2, 4, 3, 5, 1};
  return 0;
}
