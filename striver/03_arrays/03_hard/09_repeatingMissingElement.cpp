// given an array of n integers from [1..n]
// the array contains one missing and one repeating number
// i.e a number between 1 to n is missing, while a single number b/w 1 and n
// appears twice find those numbers
#include <algorithm>
#include <vector>

std::vector<int> brute(std::vector<int> &a) {
  int repeating = -1, missing = -1;
  int n = a.size();
  for (int i = 1; i <= n; i++) {
    int count = 0;
    for (int j = 0; j < n; j++) {
      if (i == a[j])
        count++;
    }
    if (count == 2)
      repeating = i;
    if (count == 0)
      missing = i;

    // if both are found, then break out
    if (repeating != -1 && missing != -1)
      break;
  }

  return {repeating, missing};
}

std::vector<int> better(std::vector<int> &a) {
  int n = a.size();
  int max_value = *std::max_element(a.begin(), a.end());
  std::vector<int> hashArray(max_value + 1, 0);

  for (int i = 0; i < n; i++) {
    hashArray[a[i]]++;
  }

  int repeating = -1, missing = -1;
  for (int i = 1; i <= n; i++) {
    if (hashArray[i] == 0)
      missing = hashArray[i];
    if (hashArray[i] == 2)
      repeating = hashArray[i];
    if (repeating != -1 && missing != -1)
      break;
  }

  return {repeating, missing};
}

// optimal approach using Maths
std::vector<int> optimalMaths(std::vector<int> &a) {
  int n = a.size();
  long long sN = 1LL * (n * (n + 1)) / 2;
  long long sI = 0;
  for (int i : a) {
    sI += (long long)i;
  }

  long long sN2 = 1LL * (n * (n + 1) * (2 * n + 1)) / 2;
  long long sI2 = 0;
  for (int i : a) {
    sI2 += ((long long)i * (long long)i);
  }

  // let X -> repeating, Y -> Missing
  long long XminusY = sI - sN;
  long long X2minusY2 = sI2 - sN2;
  long long XplusY = X2minusY2 / XminusY;

  long long sum = XminusY + XplusY;
  long long x = sum / 2;
  long long y = XplusY - x;

  return {(int)x, (int)y};
}

int main(int argc, char *argv[]) {
  std::vector<int> array = {1, 2, 3, 6, 7, 5, 7};
  return 0;
}
