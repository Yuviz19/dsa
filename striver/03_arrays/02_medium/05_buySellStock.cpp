// You are given an array of prices where prices[i] is the price of a given
// stock on an ith day. You want to maximize your profit by choosing a single
// day to buy one stock and choosing a different day in the future to sell that
// stock. Return the maximum profit you can achieve from this transaction. If
// you cannot achieve any profit, return 0.

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int brute(std::vector<int> &a) {
  int max_profit = 0;

  for (int i = 0; i < a.size(); i++) {
    int profit = 0; // profit if stock was bought on ith day
    for (int j = i; j < a.size(); j++) {
      profit = a[j] - a[i];
      max_profit = std::max(profit, max_profit);
    }
  }

  return max_profit;
}

int optimal(std::vector<int> &a) {
  int max_profit = 0;
  int min_stock_value = INT_MAX;

  for (int i = 0; i < a.size(); i++) {
    if (a[i] < min_stock_value) {
      min_stock_value = a[i];
    }

    int profit = a[i] - min_stock_value;
    max_profit = std::max(max_profit, profit);
  }

  return max_profit;
}

int main(int argc, char *argv[]) {
  std::vector<int> arr = {7, 1, 5, 3, 6, 4};
  std::cout << brute(arr) << "\n";

  return 0;
}
