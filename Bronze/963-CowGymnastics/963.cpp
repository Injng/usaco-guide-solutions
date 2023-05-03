#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setIO("gymnastics");
  int k;
  int n;
  cin >> k >> n;

  bool pairs[n][n];
  memset(pairs, false, sizeof(pairs));
  int data[k][n];
  int count = 0;

  for (int a = 0; a < k; a++) {
    for (int b = 0; b < n; b++) {
      cin >> data[a][b];
    }
  }

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n - 1; j++) {
      for (int h = j + 1; h < n; h++) {
	pairs[data[i][j] - 1][data[i][h] - 1] = true;
      }
    }
  }

  for (int c = 0; c < n; c++) {
    for (int d = 0; d < n; d++) {
      if (pairs[c][d] == true) {
	if (pairs[d][c] == true) {
	  continue;
	} else {
	  count++;
	}
      }
    }
  }

  cout << count << "\n";
}
