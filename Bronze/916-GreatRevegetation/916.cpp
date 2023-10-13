#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("revegetate.in", "r", stdin);
  freopen("revegetate.out", "w", stdout);

  int n, m;
  cin >> n >> m;
  vector<int> pastures[n];

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    pastures[a-1].push_back(b-1);
    pastures[b-1].push_back(a-1);
  }

  int types[n];
  fill_n(types, n, 5);

  for (int i = 0; i < n; i++) {
    int possible[5] = {1, 1, 1, 1, 1};
    for (int j = 0; j < pastures[i].size(); j++) {
      possible[types[pastures[i][j]] - 1] = 0;
    }

    int type = 5;
    for (int j = 0; j < 4; j++) {
      if (possible[j] == 1) {
	type = j + 1;
	break;
      }
    }
    types[i] = type;
  }

  for (int i = 0; i < n; i++) {
    cout << types[i];
  }
  cout << "\n";
}
