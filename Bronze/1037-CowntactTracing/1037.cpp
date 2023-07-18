#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


struct Event {
  int x;
  int y;
  int time;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("tracing.in", "r", stdin);
  freopen("tracing.out", "w", stdout);

  int n, t;
  cin >> n >> t;
  char c;
  set<int> cows;
  Event actions[t];
  vector<int> possible;
  vector<int> lowerBounds;
  vector<int> upperBounds;

  for (int i = 0; i < n; i++) {
    cin.get(c);
    int cow = c - '0';
    if (cow == 1) {
      cows.insert(i);
    }
  }

  for (int i = 0; i < t; i++) {
    int time, x, y;
    Event &ev = actions[i];
    cin >> ev.time >> ev.x >> ev.y;
  }

  sort(actions, actions + t, [&](const Event &ev1, const Event &ev2) {
    return ev1.time < ev2.time;
  });

  for (auto i : cows) {
    if (i != 1) {
      continue;
    }

    int continuous = 0;
    int shakeNum = 0;
    int changeShake = 0;
    int lowerK;
    int upperK = 501;
    for(int j = 0; j < t; j++) {
      if (continuous == 1) {
	if (actions[j].x == i || actions[j].y == i) {
	  shakeNum++;
	  if (cows.find(actions[j].y) != cows.end() || cows.find(actions[j].x) != cows.end()) {
	    lowerK = shakeNum;
	    continue;
	  } else {
	    continuous = 2;
	    break;
	  }
	} else {
	  continue;
	}
      } else if (continuous == 2) {
	if (actions[j].x == i || actions[j].y == i) {
	  shakeNum++;
	  if (cows.find(actions[j].y) == cows.end() || cows.find(actions[j].x) == cows.end()) {
	    continue;
	    if (changeShake != 1) {
	      upperK = shakeNum;
	      changeShake = 1;
	    }
	  } else {
	    continuous = 0;
	    break;
	  }
	} else {
	  continue;
	}
      }

      if (actions[j].x == i || actions[j].y == i) {
	shakeNum++;
	if (cows.find(actions[j].y) != cows.end() || cows.find(actions[j].x) != cows.end()) {
	  continuous = 1;
	  lowerK = shakeNum;
	} else {
	  break;
	}
      } else {
	continue;
      }
    }

    if (continuous == 1 || continuous == 2) {
      possible.push_back(i);
      lowerBounds.push_back(lowerK);
      upperBounds.push_back(upperK);
    }
  }

  int patientZeroes = possible.size();
  int lowerBound = *max_element(lowerBounds.begin(), lowerBounds.end());
  cout << patientZeroes << " " << lowerBound << " ";
  int upperBound = *min_element(upperBounds.begin(), upperBounds.end());
  if (upperBound > 250) {
    cout << "Infinity\n";
  } else {
    cout << upperBound << "\n";
  }
}
