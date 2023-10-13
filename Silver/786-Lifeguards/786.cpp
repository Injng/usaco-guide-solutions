#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

struct Event {
  int t;
  int id;
  bool start;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("lifeguards.in", "r", stdin);
  freopen("lifeguards.out", "w", stdout);

  int n;
  cin >> n;
  vector<Event> shifts;
  
  for (int i = 0; i < n; i++) {
    Event ev1, ev2;
    cin >> ev1.t >> ev2.t;
    ev1.id = i;
    ev1.start = true;
    ev2.id = i;
    ev2.start = false;
    shifts.push_back(ev1);
    shifts.push_back(ev2);
  }

  sort(shifts.begin(), shifts.end(), [](const Event &p1, const Event &p2) {
    return p1.t < p2.t;
  });

  int total = 0;
  set<int> cows;
  vector<int> alone(n);
  int prev = shifts[0].t;
  int curr;

  for (int i = 0; i < shifts.size(); i++) {
    curr = shifts[i].t;
    if (cows.size() == 1) alone[*cows.begin()] += curr - prev;
    if (cows.size() > 0) total += curr - prev;
    if (shifts[i].start) {
      cows.insert(shifts[i].id);
    } else {
      cows.erase(shifts[i].id);
    }
    prev = shifts[i].t;
  }

  cout << total - *min_element(alone.begin(), alone.end()) << "\n";
}
