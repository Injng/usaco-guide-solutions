#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("cowdance.in", "r", stdin);
  freopen("cowdance.out", "w", stdout);

  int n, t;
  cin >> n >> t;
  int dancers[n];

  for (int i = 0; i < n; i++) {
    cin >> dancers[i];
  }

  int l = -1;
  int r = n;

  while (r - l > 1) {
    int m = (r - l) >> 1;
    m = l + m;
    priority_queue<int, vector<int>, greater<int>> onStage;

    for (int j = 0; j < n; j++) {
      if (j < m) {
	onStage.push(dancers[j]);
      } else {
	int off = onStage.top();
	onStage.pop();
	onStage.push(dancers[j] + off);
      }
    }

    for (int j = 1; j < onStage.size(); j++) {
      onStage.pop();
    }
    int time = onStage.top();

    if (time > t) l = m;
    else r = m;
  }

  cout << r << "\n";
}
