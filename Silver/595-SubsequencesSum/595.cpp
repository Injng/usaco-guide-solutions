#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("div7.in", "r", stdin);
  freopen("div7.out", "w", stdout);

  int n;
  cin >> n;
  int psum[n + 1];
  psum[0] = 0;

  for (int i = 1; i <= n; i++) {
    int cow;
    cin >> cow;
    psum[i] = psum[i - 1] + cow;
  }

  for (int i = n; i > 0; i--) {
    for (int j = 0; j <= n - i; j++) {
      int sum = psum[j + i] - psum[j];
      if (sum % 7 == 0) {
	cout << i << "\n";
	return 0;
      }
    }
  }

  cout << "0\n";
}
