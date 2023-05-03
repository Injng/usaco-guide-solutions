#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int travel(int step) {
  if (step == 0) {
    return 0;
  } else {
    return (pow((-1), (step - 1)) * pow(2, (step - 1)));
  }
}

int main() {
  setIO("lostcow");
  
  int x;
  int y;
  cin >> x >> y;

  int step = 1;
  bool found = false;
  int distance = 0;

  while (found == false) {
    distance = distance + abs(travel(step)) + abs(travel(step - 1));
    if (x + travel(step) < x + travel(step - 1)) {
      if (y >= x + travel(step) && y <= x + travel(step - 1)) {
	  found = true;
	  distance = distance - abs(x + travel(step) - y);
      }
    } else {
      if (y <= x + travel(step) && y >= x + travel(step - 1)) {
	found = true;
	distance = distance - abs(x + travel(step) - y);
      }
    }
    step = step + 1;
  }
    
  cout << distance << "\n";
}
