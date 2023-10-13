#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cow {
  int x;
  int y;
};

bool cmpX(const Cow &a, const Cow &b) { return a.x < b.x; }
bool cmpY(const Cow &a, const Cow &b) { return a.y < b.y; }

int loc[5][5];
long long above[5][5];
long long below[5][5];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<Cow> cows;

  for (int i = 0; i < n; i++) {
    Cow input;
    cin >> input.x >> input.y;
    cows.push_back(input);
  }

  sort(cows.begin(), cows.end(), cmpY);
  int current_y = -1;
  int index_y = 1;
  for (int i = 1; i <= n; i++) {
    if (cows[i - 1].y == current_y) {
      cows.erase(cows.begin() + index_y - 1);
      continue;
    } else {
      current_y = cows[i - 1].y;
      cows[i - 1].y = index_y;
      index_y++;
    }
  }
  sort(cows.begin(), cows.end(), cmpX);
  for (int i = 1; i <= cows.size(); i++) {
    cows[i - 1].x = i;
    loc[cows[i - 1].x][cows[i - 1].y] = 1;
  }
  
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      above[i][j] = loc[i][j] + above[i - 1][j] + above[i][j - 1] - above[i - 1][j - 1];
      below[n - i][n - j] = loc[n - i + 1][n - j + 1];
      below[n - i][n - j] += below[n - i + 1][n - j] + below[n - i][n - j + 1] - below[n - i + 1][n - j + 1];
    }
  }

  long long subsets = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      Cow tr, bl;
      tr.x = cows[i].x;
      tr.y = cows[i].y > cows[j].y ? cows[i].y : cows[j].y;
      bl.x = cows[j].x;
      bl.y = cows[i].y < cows[j].y ? cows[i].y : cows[j].y;
      long long bel = below[bl.x - 1][bl.y - 1] - below[bl.x - 1][tr.y];
      long long abv = above[tr.x][tr.y] - above[tr.x][bl.y - 1];
      subsets += bel * abv;
    }
  }
  subsets += 1 + n;

  cout << subsets << "\n";
}
