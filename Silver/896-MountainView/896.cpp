#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Mountain{ 
  long long x;
  long long y;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("mountains.in", "r", stdin);
  freopen("mountains.out", "w", stdout);

  int n;
  cin >> n;
  vector<Mountain> bases;

  for (int i = 0; i < n; i++) {
    Mountain m1;
    int x, y;
    cin >> x >> y;
    m1.x = x - y;
    m1.y = x + y;
    bases.push_back(m1);
  }

  sort(bases.begin(), bases.end(), [](const Mountain &e1, const Mountain &e2) {
    return e1.x < e2.x;
  });

  int rightmost = -1;
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (bases[i].y > rightmost) {
      rightmost = bases[i].y;
      count++;
    } else {
      continue;
    }
  }

  cout << count << "\n";
}


