#include <iostream>
#include <algorithm>

using namespace std;

bool isEven(int n) {
  if (n % 2 == 0) return true;
  else return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int arr[n];
    int sorted[n];

    for (int j = 0; j < n; j++) {
      cin >> arr[j];
      sorted[j] = arr[j];
    }

    sort(sorted, sorted+n);
    int yes = 0;

    for (int j = 0; j < n; j++) {
      if (isEven(arr[j]) == isEven(sorted[j])) {
        continue;
      } else {
        yes = 1;
        break;
      }
    }

    if (yes == 0) cout << "YES\n";
    else cout << "NO\n";
  }
}
