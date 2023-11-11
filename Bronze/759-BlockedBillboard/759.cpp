#include <iostream>
#include <cstdio>
using namespace std;

int intersection(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4) {
  int xIntersect = max(0, min(x2, x4) - max(x1, x3));
  int yIntersect = max(0, min(y2, y4) - max(y1, y3));
  return xIntersect * yIntersect;
}

int main() {
  freopen("billboard.in", "r", stdin);
  freopen("billboard.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int a1, a2, a3, a4, b1, b2, b3, b4, c1, c2, c3, c4;
  cin >> a1 >> a2 >> a3 >> a4;
  cin >> b1 >> b2 >> b3 >> b4;
  cin >> c1 >> c2 >> c3 >> c4;

  int totalarea = (a4 - a2) * (a3 - a1) +  (c4 - c2) * (c3 - c1);
  int leftblocked = intersection(a1, a3, b1, b3, a2, a4, b2, b4);
  int rightblocked = intersection(b1, b3, c1, c3, b2, b4, c1, c3);
  int totalblocked = leftblocked + rightblocked;

  int area = totalarea - totalblocked;
  cout << area << "\n";
}

