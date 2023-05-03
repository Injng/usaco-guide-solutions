#include <iostream>
#include <vector>

using namespace std;

void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setIO("pails");
  int x;
  int y;
  int m;
  int total;
  cin >> x >> y >> m;
  vector<int> possible;
  int maxX = (m / x) + 1;
  int maxY = (m / y) + 1;

  for (int i = 1; i <= maxX; i++) {
    for (int j = 1; j <= maxY; j++) {
      total = i * x  + j * y;
      if (total <= m) {
	possible.push_back(total);
      } else {
	continue;
      }
    }
  }

  cout << *max_element(possible.begin(), possible.end()) << "\n";
}
  
