#include <iostream>
#include <set>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    long long int delta[n - 1];
    long long int prev, curr;
    prev = 0;

    for (int j = 0; j < n - 1; j++) {
      cin >> curr;
      delta[j] = curr - prev;
      prev = curr;
    }

    set<long long int> removed;
    long long int count = 0;
    long long int larger;

    for (int j = 0; j < n - 1; j++) {
      if (delta[j] <= n && removed.find(delta[j]) == removed.end()) {
        removed.insert(delta[j]);
        continue;
      } else {
        count++;
        larger = delta[j];
      }
    }

    if (count > 1) {
      cout << "NO\n";
    } else if (count == 1) {
      long long int sum = 0;
      for (int i = 1; i <= n; i++) {
        if (removed.find(i) == removed.end()) sum += i;
      }
      if (sum == larger) cout << "YES\n";
      else cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}
