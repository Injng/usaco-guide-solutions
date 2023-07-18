#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    int ct = n;
    vector<int> patterns;

    while (ct--) {
      int p;
      cin >> p;
      patterns.push_back(p);
    }

    sort(patterns.begin(), patterns.end());
    int l = -1;
    int r = patterns[n - 1];

    while (r - l > 1) {
      int m = (l + r) / 2;

      int a = 0;
      while (a < n && patterns[a] - patterns[0] <= 2 * m) {
	a++;
      }

      int b = n - 1;
      while (b >= 0 && patterns[n - 1] - patterns[b] <= 2 * m) {
	b--;
      }

      if (a > b || patterns[b - 1] - patterns[a + 1] < 2 * m) {
	r = m;
      } else {
	l = m;
      }
    }

    cout << r << "\n";
  }
}
