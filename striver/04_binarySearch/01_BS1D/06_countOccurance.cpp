// count the number of occurances of the target element in the given array

#include <vector>

int firstOccurance(std::vector<int> &a, int x) {
  int n = a.size();
  int low = 0, high = n - 1;
  int latestOccurance = -1;

  while (low <= high) {
    int mid = (low + high) / 2;

    if (a[mid] == x) {
      latestOccurance = mid;
      high = mid - 1;
    } else if (a[mid] > x) {
      high = mid - 1;
    } else
      low = mid + 1;
  }

  return latestOccurance;
}

int lastOccuramce(std::vector<int> &a, int x) {
  int n = a.size();
  int low = 0, high = n - 1;
  int latestOccurance = -1;

  while (low <= high) {
    int mid = (low + high) / 2;
    if (a[mid] == x) {
      latestOccurance = mid;
      low = mid + 1;
    } else if (a[mid] > x) {
      high = mid - 1;
    } else
      low = mid + 1;
  }

  return latestOccurance;
}

int occurances(std::vector<int> &a, int x) {
  int first = firstOccurance(a, x);
  int last = lastOccuramce(a, x);

  int count = last - first + 1;

  return count;
}

int main(int argc, char *argv[]) {
  std::vector<int> array = {2, 2, 3, 3, 3, 3, 4};
  int target = 3, occurances = 0;
  int n = array.size();
  int low = 0, high = n - 1;
  return 0;
}
