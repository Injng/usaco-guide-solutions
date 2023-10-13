#include <iostream>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;
  int inpt[n+1][m+1];
  int blus[n+1][m+1];
  fill(&blus[0][0], &blus[0][0] + sizeof(blus), 0);
  int rows[n+1][m+1];
  fill(&rows[0][0], &rows[0][0] + sizeof(rows), 0);
  int cols[n+1][m+1];
  fill(&cols[0][0], &cols[0][0] + sizeof(cols), 0);

  for (int i = 0; i < n + 1; i++) {
    string row;
    if (i != 0) {
      cin >> row;
    } else {
      row = "";
    }

    for (int j = 0; j < m + 1; j++) {
      if (i == 0 || j == 0) {
        inpt[i][j] = 0;
        continue;
      } else {
        inpt[i][j] = row[j - 1] - '0';
      }
    }
  }

  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < m + 1; j++) {
      if (i && j) {
        blus[i][j] = inpt[i][j];
        blus[i][j] += blus[i - 1][j] + blus[i][j - 1] - blus[i - 1][j - 1];
        rows[i][j] += rows[i - 1][j] + rows[i][j - 1] - rows[i - 1][j - 1];
        rows[i][j] += (inpt[i][j] && inpt[i][j - 1]) ? 1 : 0;
        cols[i][j] += cols[i - 1][j] + cols[i][j - 1] - cols[i - 1][j - 1];
        cols[i][j] += (inpt[i][j] && inpt[i - 1][j]) ? 1 : 0;
      }
    }
  }

  for (int i = 0; i < q; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int squares = blus[x2][y2] - blus[x2][y1 - 1] - blus[x1 - 1][y2] + blus[x1 - 1][y1 - 1];
    int crows = rows[x2][y2] - rows[x2][y1] - rows[x1 - 1][y2] + rows[x1 - 1][y1];
    int ccols = cols[x2][y2] - cols[x2][y1 - 1] - cols[x1][y2] + cols[x1][y1 - 1];
    cout << squares - crows - ccols << "\n";
  }
}
