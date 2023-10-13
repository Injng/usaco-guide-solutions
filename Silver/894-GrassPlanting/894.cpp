#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("planting.in", "r", stdin);
  freopen("planting.out", "w", stdout);

  int n;
  cin >> n;
  int sums[n];
  fill(sums, sums+n, 0);

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    sums[a - 1]++;
    sums[b - 1]++;
  }

  cout << *max_element(sums, sums+n) + 1 << "\n";
}

