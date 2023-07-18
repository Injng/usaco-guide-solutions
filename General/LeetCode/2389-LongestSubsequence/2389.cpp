#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> nums = {4, 5, 2, 1};
  vector<int> queries = {3, 10, 21};
  vector<int> sums;

  sort(nums.begin(), nums.end());

  int sum = 0;
  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
    sums.push_back(sum);
  }

  for (int i = 0; i < queries.size(); i++) {
    int query = queries[i];
    auto bound = upper_bound(sums.begin(), sums.end(), query);
    cout << bound - sums.begin()  << "\n";
  }
}
