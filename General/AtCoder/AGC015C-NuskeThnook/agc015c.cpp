#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;
  // 建立数组给存储输入信息和前缀和
  char grid[n + 1][m + 1];
  int squares[n + 1][m + 1];
  int rows[n + 1][m + 1];
  int cols[n + 1][m + 1];

  // 读输入信息
  for (int i = 0; i < n + 1; i++) {
    string row = "";
    if (i != 0) {
      cin >> row;
    }
    for (int j = 0; j < m + 1; j++) {
      if (j == 0 || i == 0) {
        grid[i][j] = '0';
        squares[i][j] = 0;
        rows[i][j] = 0;
        cols[i][j] = 0;
        continue;
      } else {
        grid[i][j] = row[j - 1];
      }
    }
  }
  
  // 建造前缀和
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < m + 1; j++) {
      squares[i][j] = squares[i - 1][j] + squares[i][j - 1] - squares[i - 1][j - 1];
      rows[i][j] = rows[i - 1][j] + rows[i][j - 1] - squares[i - 1][j - 1];
      cols[i][j] = cols[i - 1][j] + cols[i][j - 1] - cols[i - 1][j - 1];

      if (grid[i][j] == '1') {
        squares[i][j]++;
        if (grid[i - 1][j] == '1') cols[i][j]++;
        if (grid[i][j - 1] == '1') rows[i][j]++;
      }
    }
  }

  // 操作查询
  for (int i = 0; i < q; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int square = squares[x2][y2] - squares[x2][y1 - 1] - squares[x1][y2 - 1] + squares[x1 - 1][y1 - 1];
    int row = rows[x2][y2] - rows[x2][y1 - 1] - rows[x1][y2 - 1] + rows[x1 - 1][y1 - 1];
    int col = cols[x2][y2] - cols[x2][y1 - 1] - cols[x1][y2 - 1] + cols[x1 - 1][y1 - 1];
    cout << square - row - col << "\n";
  }
}
