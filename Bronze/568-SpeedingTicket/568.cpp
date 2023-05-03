#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  int limit[100];
  int speed[100];
  int delta[100];
  int first = 0;

  for (int i = 0; i < n; i++) {
    int dist, slimit;
    cin >> dist >> slimit;
    for (int j = first; j < first + dist; j++) {
      limit[j] = slimit;
    }
    first = first + dist;
  }

  first = 0;

  for (int i = 0; i < m; i++) {
    int dist, sactual;
    cin >> dist >> sactual;
    for (int j = first; j < first + dist; j++) {
      speed[j] = sactual;
    }
    first = first + dist;
  }

  for (int a = 0; a < 100; a++) {
    delta[a] = speed[a] - limit[a];
  }

  cout << *max_element(delta, delta + 100) << "\n";
}
