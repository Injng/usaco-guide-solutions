#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  char forest[n][n]; // read input
  int trees[n + 1][n + 1]; // 2d prefix sum

  for (int i = 0; i < n; i++) {
    string row;
    cin >> row;
    for (int j = 0; j < n; j++) {
      forest[i][j] = row[j];
    }
  }

  for (int i = 0; i < n + 1; i++) {
    if (i == 0) {
      for (int j = 0; j < n + 1; j++) {
	trees[0][j] = 0;
      }
      continue;
    }

    trees[i][0] = 0;
    for (int j = 1; j < n + 1; j++) {
      trees[i][j] = trees[i - 1][j] + trees[i][j - 1] - trees[i - 1][j - 1];
      if (forest[i - 1][j - 1] == '*') trees[i][j]++;
    }
  }

  for (int i = 0; i < q; i++) {
    int x1, y1, x2, y2;
    cin >> y1 >> x1 >> y2 >> x2;
    cout << trees[y2][x2] - trees[y2][x1 - 1] - trees[y1 - 1][x2] + trees[y1 - 1][x1 - 1] << "\n";
  }
}
