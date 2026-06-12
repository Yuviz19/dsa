#include <iostream>
#include <vector>

// approach 1 can be to use a set
// loop through both the entire arrays
// and add the elements to a set
// then copy the set to a final array
// time comp - O({n+m}logn)
// space comp - O(n+m) + O(n+m) - one for set and the other for union array

// a 2 pointer approach
std::vector<int> unionSortedArrays(std::vector<int> &a, std::vector<int> &b) {
  std::vector<int> unionArr;
  int i = 0, j = 0;

  // start from the start of both the arrays, unitl either end is reached
  while (i < a.size() && j < b.size()) {
    // if the element of i is smaller
    if (a[i] < b[j]) {
      // check if the array is empty, or the last element is equal to the
      // inserting array
      if (unionArr.empty() || unionArr.back() != a[i]) {
        unionArr.push_back(a[i]);
      }
      i++;
    }

    // the same situation for j (2nd array)
    else if (a[i] > a[j]) {
      if (unionArr.empty() || unionArr.back() != b[j]) {
        unionArr.push_back(b[j]);
      }
      j++;
    }

    // if both are same, push_back the 1st array element
    else {
      if (unionArr.empty() || unionArr.back() != a[i]) {
        unionArr.push_back(a[i]);
      }
      // increment both the array's pointer
      i++;
      j++;
    }
  }
  // put back the rest of the arrays
  while (i < a.size()) {
    if (unionArr.empty() || unionArr.back() != a[i]) {
      unionArr.push_back(a[i]);
    }
    i++;
  }

  while (j < b.size()) {
    if (unionArr.empty() || unionArr.back() != b[j]) {
      unionArr.push_back(b[j]);
    }
    j++;
  }

  return unionArr;
}

int main(int argc, char *argv[]) {
  std::vector<int> arr1 = {1, 2, 3, 4, 5};
  std::vector<int> arr2 = {2, 3, 4, 4, 5};

  std::vector<int> unionArr = unionSortedArrays(arr1, arr2);
  for (auto it : unionArr) {
    std::cout << it << " ";
  }
  return 0;
}
