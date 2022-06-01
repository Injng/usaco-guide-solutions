#include <iostream>
#include <vector>

using namespace std;

void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setIO("blist");
  
  int n, t, s, b;
  int total = 0;
  int ans = 0;
  cin >> n;
  vector<int> buckets(1002, 0);

  for (int x = 0; x < n; ++x) {
    cin >> s >> t >> b;
    buckets[s] += b;
    buckets[t + 1] -= b;    
  }

  for (int y = 0; y <= 1001; ++y) {
    total += buckets[y];
    ans = max(ans, total);
  }

  cout << ans;
}

