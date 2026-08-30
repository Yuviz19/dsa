#include <set>
#include <vector>

int missingMultiple(std::vector<int> &nums, int k) {
  std::set<int> st;
  for (auto i : nums) {
    st.insert(i);
  }

  for (int i = 1; i < 100; i++) {
    if (st.find(k * i) == st.end())
      return k * i;
  }

  return -1;
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {1, 4, 7, 10, 15};
  return 0;
}
