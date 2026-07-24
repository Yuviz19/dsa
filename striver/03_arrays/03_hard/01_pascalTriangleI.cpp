// WAP to generate the pascal's triangle
// where each number is the sum of the two numbers directly above it

// #include <iostream>
#include <vector>

// given a row and a column number, return the number at that position
// we find (r - 1) C (c - 1) -> returns the element at (r,c) coordinate
long long ncr(int r, int c) {
  long long result = 1;
  for (int i = 0; i < r; i++) {
    result = result * (c - 1);
    result = result / (i + 1);
  }

  // this works as the (n-r) thing is cancles the terms of n
  // hence as many digits remains as there are in r!

  return result;
}

// print the nth row of the pascal's triangle
// in nth row there are n elements
void brute_forSingleRow(int n) {
  for (int c = 1; c <= n; c++) {
    // call the ncr function
  }
}

std::vector<int> optimal_forSingleRow(int n) {
  long long ans = 1;
  std::vector<int> ansRow;
  ansRow.push_back(ans);
  for (int i = 1; i < n; i++) {
    ans *= (n - i);
    ans /= (i);
    ansRow.push_back(ans);
  }

  return ansRow;
}

// print the entire pascal triangle till row n
// the key idea is to just use the above function and then store it inside
// another list
std::vector<std::vector<int>> PasclaTriangle(int N) {
  std::vector<std::vector<int>> ans;

  for (int i = 1; i <= N; i++) {
    ans.push_back(optimal_forSingleRow(i));
  }

  return ans;
}

int main(int argc, char *argv[]) { return 0; }
