#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("hps.in", "r", stdin);
  freopen("hps.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> games[n + 1];
  games[0] = {0, 0, 0};
  map<char, int> plays;
  plays['H'] = 0;
  plays['P'] = 1;
  plays['S'] = 2;
  vector<int> sums;

  for (int i = 1; i <= n; i++) {
    char play;
    cin >> play;
    games[i] = games[i - 1];
    games[i][plays[play]]++;
  }

  for (int i = n; i > 0; i--) {
    vector<int> top;
    top.push_back(games[n][0] - games[i][0]);
    top.push_back(games[n][1] - games[i][1]);
    top.push_back(games[n][2] - games[i][2]);
    int max = *max_element(top.begin(), top.end()) + *max_element(games[i].begin(), games[i].end());
    sums.push_back(max);
  }

  cout << *max_element(sums.begin(), sums.end()) << "\n";
}
