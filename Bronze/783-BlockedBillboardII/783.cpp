#include <iostream>
#include <cstdio>

using namespace std;


void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}



int intersection(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4) {
  int xIntersect = max(0, min(x2, x4) - max(x1, x3));
  int yIntersect = max(0, min(y2, y4) - max(y1, y3));
  return xIntersect * yIntersect;
}


int main() {
  setIO("billboard");
  int x1, y1, x2, y2, x3, y3, x4, y4;
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> x3 >> y3 >> x4 >> y4;

  int counter = 0;

  if (x1 > x3 && x1 < x4) {
    if (y1 > y3 && y1 < y4) {
      ++counter;
    }

    if (y2 > y3 && y2 < y4) {
      ++counter;
    }
  }

  if (x2 > x3 && x2 < x4) {
    if (y1 > y3 && y1 < y4) {
      ++counter;
    }

    if (y2 > y3 && y2 < y4) {
      ++counter;
    }
  }

  if (counter == 1) {
    cout << (x2 - x1) * (y2 - y1) << "\n";
  } else if (counter == 2) {
    cout << (x2 - x1) * (y2 - y1) - intersection(x1, x2, x3, x4, y1, y2, y3, y4) << "\
      n";
  } else if (counter == 3) {
    cout << "Error\n";
  } else if (counter == 4) {
    cout << 0;
  } else {
    cout << "Error\n";
  }
}
    

  
  
