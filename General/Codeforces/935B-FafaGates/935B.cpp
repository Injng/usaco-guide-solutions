#include <iostream>
#include <string>
using namespace std;

int coordinates(int x, int y, char move, int det) {
  if (move == 'R') {
    if (det >= 0) ++x;
    else --x;
  } else {
    if (det >= 0) ++y;
    else --y;
  }

  if (det == 0 || det == -1) return x;
  else if (det == 1 || det == -2) return y;
  else return 0;
}
  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string moves;
  int x, y = 0;
  int coins = 0;

  cin >> n >> moves;

  for (int i = 0; i < n; ++i) {
    int prevkingdom;
    int currkingdom;
    int nextx;
    int nexty;
    int prevx;
    int prevy;

    if (i == 0) {
      prevkingdom = 0;
    } else {
      prevkingdom = currkingdom;
    }

    x = coordinates(x, y, moves[i], 0);
    y = coordinates(x, y, moves[i], 1);

    if (x > y) {
      currkingdom = -1;
    } else if (x < y) {
      currkingdom = 1;
    } else {
      currkingdom = 0;
      if (i != 0 && i != n - 1) {
	nextx = coordinates(x, y, moves[i + 1], 0);
	nexty = coordinates(x, y, moves[i + 1], 1);
        prevx = coordinates(x, y, moves[i], -1);
	prevy = coordinates(x, y, moves[i], -2);

	if ((nextx > nexty && prevx < prevy) || (nextx < nexty && prevx > prevy)) {
	  ++coins;
	}
      }
    }
  }

  cout << coins << "\n";
}

