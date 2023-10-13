#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("tttt.in", "r", stdin);
  freopen("tttt.out", "w", stdout);

  char board[3][3];
  int single = 0;
  int pair = 0;
  
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> board[i][j];
    }
  }

  char lines[8][3];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      lines[i][j] = board[i][j];
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      lines[3 + i][j] = board[j][i];
    }
  }

  lines[6][0] = board[0][0];
  lines[6][1] = board[1][1];
  lines[6][2] = board[2][2];

  lines[7][0] = board[0][2];
  lines[7][1] = board[1][1];
  lines[7][2] = board[2][0];

  for (int i = 0; i < 8; i++) {
    set<char> cows;
    for (int j = 0; j < 3; j++) {
      cows.insert(lines[i][j]);
    }

    int uniqueness = cows.size();
    if (uniqueness == 1) {
      single++;
    } else if (uniqueness == 2) {
      pair++;
    } else {
      continue;
    }
  }

  cout << single << "\n";
  cout << pair << "\n";
}
    
