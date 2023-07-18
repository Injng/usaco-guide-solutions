#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    long long n;
    cin >> n;
    long long sum = 0;

    while (n > 0) {
      sum += n;
      n = n >> 1;
    }

    cout << sum << "\n";
  }
}
