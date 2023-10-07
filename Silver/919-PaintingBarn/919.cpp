#include <iostream>

using namespace std;

int dp[1001][1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("paintbarn.in", "r", stdin);
  freopen("paintbarn.out", "w", stdout);

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    dp[x1][y1]++;
    dp[x1][y2]--;
    dp[x2][y1]--;
    dp[x2][y2]++;
  }

  int res = 0;

  for (int i = 0; i < 1001; i++) {
    for (int j = 0; j < 1001; j++) {
      if (i) dp[i][j] += dp[i - 1][j];
      if (j) dp[i][j] += dp[i][j - 1];
      if (i && j) dp[i][j] -= dp[i - 1][j - 1];
      if (dp[i][j] == k) res++; 
    }
  }

  cout << res << "\n";
}
