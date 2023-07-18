#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("bcount.in", "r", stdin);
  freopen("bcount.out", "w", stdout);

  int n, q;
  cin >> n >> q;
  vector<int> line[n + 1];
  line[0] = {0, 0, 0};
  map<int, int> amt;
  amt[1] = 0;
  amt[2] = 0;
  amt[3] = 0;

  for (int i = 0; i < n; i++) {
    int type;
    cin >> type;
    amt[type]++;
    vector<int> psum = {amt[1], amt[2], amt[3]};
    line[i + 1] = psum;
  }

  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    for (int j = 0; j < 3; j++) {
      cout << line[b][j] - line[a - 1][j];
      if (j != 2) cout << " ";
    }
    cout << "\n";
  }
}
