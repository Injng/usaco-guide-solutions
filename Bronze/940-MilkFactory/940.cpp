#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("factory.in", "r", stdin);
  freopen("factory.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> belts[n];

  for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    belts[a-1].push_back(b-1);
  }

  int sink = -1;
  for (int i = 0; i < n; i++) {
    if (belts[i].size() == 0) {
      if (sink == -1) {
	sink = i + 1;
      } else {
	cout << -1 << "\n";
	return 0;
      }
    }
  }

  cout << sink << "\n";
}
