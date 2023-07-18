#include <iostream>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int combination[n];

  for (int i = 0; i < n; i++) {
    cin >> combination[i];
  }

  for (int mask = 0; mask < (1 << n); mask++) {
    int position = 0;
    for (int j = 0; j < n; j++) {
      if (mask & (1 << j)) {
	position += combination[j];
      } else {
	position -= combination[j];
      }
    }

    if (abs(position) % 360 == 0) {
      cout << "YES\n";
      return 0;
    }
  }

  cout << "NO\n";
}
