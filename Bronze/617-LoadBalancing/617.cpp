#include <iostream>
#include <algorithm>

using namespace std;

void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int maxCows(int x, int y, int locations[][2], int n) {
  setIO("balancing");
  int quadI = 0;
  int quadII = 0;
  int quadIII = 0;
  int quadIV = 0;

  for (int a = 0; a < n; a++) {
    if (locations[a][0] < x) {
      if (locations[a][1] < y) {
	quadIII++;
      } else {
	quadII++;
      }
    } else {
      if (locations[a][1] < y) {
	quadIV++;
      } else {
	quadI++;
      }
    }
  }

  int quadrants[4] = {quadI, quadII, quadIII, quadIV};
  int &min = *max_element(quadrants, quadrants + 4);
  return min;
}

int main() {
  int n;
  int b;
  cin >> n >> b;
  int locations[n][2];
  int xtests[n];
  int ytests[n];

  for (int x = 0; x < n; x++) {
    cin >> locations[x][0] >> locations[x][1];
  }

  for (int i = 0; i < n; i++) {
    xtests[i] = locations[i][0] + 1;
    ytests[i] = locations[i][1] + 1;
  }

  int values[n * n];
  int count = 0;

  for (int b : xtests) {
    for (int c : ytests) {
      values[count] = maxCows(b, c, locations, n);
      count++;
    }
  }

  int &ans = *min_element(values, values + n * n);

  cout << ans << "\n";
}
  

  

  
  
