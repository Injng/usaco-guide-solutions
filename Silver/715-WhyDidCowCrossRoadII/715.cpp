#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("maxcross.in", "r", stdin);
  freopen("maxcross.out", "w", stdout);

  int n, k, b;
  cin >> n >> k >> b;
  int signals[n]{};
  int broken[n + 1];
  broken[0] = 0;
  vector<int> toFix;

  for (int i = 0; i < b; i++) {
    int id;
    cin >> id;
    signals[id - 1] = 1;
  }

  for (int i = 0; i < n; i++) {
    broken[i + 1] = broken[i];
    if (signals[i] == 1) {
      broken[i + 1]++;
    }
  }

  for (int i = 0; i <= n - k; i++) {
    int needFix = broken[i + k] - broken[i];
    toFix.push_back(needFix);
  }

  cout << *min_element(toFix.begin(), toFix.end()) << "\n";
}
