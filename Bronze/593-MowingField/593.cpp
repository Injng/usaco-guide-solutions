#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>

using namespace std;

int checkCross(int x) {
  if (x == 0) {
    return 0;
  } else {
    return x;
  }
}
  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("mowing.in", "r", stdin);
  freopen("mowing.out", "w", stdout);

  int n;
  cin >> n;
  pair<int, int> location{0, 0};
  map<pair<int, int>, int> path{{location, 0}};
  int time = 0;
  vector<int> growth;

  for (int i = 0; i < n; i++) {
    char direction;
    int units;
    cin >> direction >> units;

    switch (direction) {
    case 'N':
      for (int j = 0; j < units; j++) {
	time++;
	location.second++;
	if (path.count(location) == 1) {
	  growth.push_back(time - path[location]);
	}
	path[location] = time;
      }
      break;
    case 'E':
      for (int j = 0; j < units; j++) {
	time++;
	location.first++;
	if (path.count(location) == 1) {
	  growth.push_back(time - path[location]);
	}
	path[location] = time;
      }
      break;
    case 'S':
      for (int j = 0; j < units; j++) {
	time++;
	location.second--;
	if (path.count(location) == 1) {
	  growth.push_back(time - path[location]);
	}
	path[location] = time;
      }
      break;
    case 'W':
      for (int j = 0; j < units; j++) {
	time++;
	location.first--;
	if (path.count(location) == 1) {
	  growth.push_back(time - path[location]);
	}
	path[location] = time;
      }
      break;
    }
  }
  
  if (growth.empty()) {
    cout << "-1\n";
  } else {
    cout << *min_element(growth.begin(), growth.end()) << "\n";
  }
}
