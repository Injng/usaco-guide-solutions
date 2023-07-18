#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int amt = 0;

    for (int j = 0; j < n; j++) {
      int a, b;
      cin >> a >> b;
      if (a - b <= 0) {
	amt++;
      }
    }

    cout << n - amt << "\n";
  }
}
