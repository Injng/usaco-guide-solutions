#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n, m, h;
    cin >> n >> m >> h;
    vector<int> standings[n];

    for (int j = 0; j < n; j++) {
      int problems[m];

      for (int k = 0; k < m; k++) {
	cin >> problems[k];
      }

      sort(problems, problems+m);
      int time = problems[0];
      int index = 0;
      int score = 0;
      int penalty = 0;
      int sum = 0;

      while (time <= h && index < m) {
	score++;
	penalty = penalty + sum + problems[index];
	sum += problems[index];
	time += problems[index+1];
	index++;
      }

      standings[j].push_back(score);
      standings[j].push_back(penalty);
      standings[j].push_back(j);
    }

    sort(standings, standings+n, [&](const vector<int> &v1, const vector<int> &v2) {
      if (v1[0] == v2[0]) {
	if (v1[1] == v2[1]) {
	  return false;
	} else {
	  return v1[1] < v2[1];
	}
      } else {
	return v1[0] > v2[0];
      }
    });

    for (int k = 0; k < n; k++) {
      if (standings[k][2] == 0) {
	cout << k + 1 << "\n";
      }
    }
  }	
}
