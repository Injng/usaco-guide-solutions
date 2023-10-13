#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("convention.in", "r", stdin);
  freopen("convention.out", "w", stdout);

  int n, m, c;
  cin >> n >> m >> c;
  vector<int> arrivals;

  for (int i = 0; i < n; i++) {
    int time;
    cin >> time;
    arrivals.push_back(time);
  }

  sort(arrivals.begin(), arrivals.end());
  int l = -1;
  int r = 1e9;

  while (r - l > 1) {
    int mid = (r - l) >> 1;
    mid = mid + l;
    int buses = 0;
    int wait = arrivals[0];
    int souls = 0;

    for (int j = 0; j < n; j++) {
      if (arrivals[j] - wait > mid || souls + 1 > c) {
	buses++;
	wait = arrivals[j];
	souls = 1;
      } else {
	souls++;
      }
    }

    buses++;
    if (buses > m) l = mid;
    else r = mid;
  }

  cout << r << "\n";
}
