// You are given a positive integer n
// Your task is to find and return its square root

// brute
int findSqrtBrute(int &n) {
  int i = 1;
  int ans = 0;

  while ((i * i) <= n) {
    ans = i;
    i++;
  }

  return ans;
}

// now using the binary search
int findSqrt(int &n) {
  int low = 1, high = n;
  int ans = 0;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (mid * mid <= n) {
      ans = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return ans;
}

int main(int argc, char *argv[]) {
  int n = 28;
  return 0;
}
