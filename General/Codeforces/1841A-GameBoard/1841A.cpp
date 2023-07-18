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
    if (n <= 4) {
      cout << "Bob\n";
    } else {
      cout << "Alice\n";
    }
  }
}
