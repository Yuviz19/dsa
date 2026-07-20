// #include <iostream>
#include <stack>
#include <vector>

std::stack<int> leader(std::vector<int> &a) {
  std::stack<int> st;

  int n = a.size();
  int leaderElement = a[n - 1];
  st.push(leaderElement);
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] > leaderElement) {
      leaderElement = a[i];
      st.push(a[i]);
    }
  }

  return st;
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {4, 7, 1, 0};
  return 0;
}
