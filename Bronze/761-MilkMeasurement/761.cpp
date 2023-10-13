#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("measurement.in", "r", stdin);
  freopen("measurement.out", "w", stdout);

  vector<tuple<int, string, int>> log;
  map<string, int> board{{"Bessie", 7}, {"Elsie", 7}, {"Mildred", 7}};
  int changes = 0;
  vector<string> previous = {"Bessie", "Elsie", "Mildred"};
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int time;
    string cow;
    int delta;
    cin >> time >> cow >> delta;
    log.push_back(tuple<int, string, int>{time, cow, delta});
  }

  sort(log.begin(), log.end(), [](auto &left, auto &right) {
    return get<0>(left) < get<0>(right);
  });

  for (int i = 0; i < n; i++) {
    board[get<1>(log[i])] = board[get<1>(log[i])] + get<2>(log[i]);
    vector<string> maxCows;
    int max = 0;
    for (auto j : board) {
      if (j.second > max) {
	max = j.second;
	maxCows.clear();
	maxCows.push_back(j.first);
      } else if (j.second == max) {
	maxCows.push_back(j.first);
      } else {
	continue;
      }
    }

    if (previous.size() == maxCows.size()) {
      for (int j = 0; j < previous.size(); j++) {
	if (previous[j] != maxCows[j]) {
	  changes++;
	  previous = maxCows;
	  break;
	} else {
	  continue;
	}
      }
    } else {
      changes++;
      previous = maxCows;
    }
  }

  cout << changes << "\n";
}
