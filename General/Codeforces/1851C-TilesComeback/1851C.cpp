#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n, k;
    cin >> n >> k;
    int arr[n];

    for (int j = 0; j < n; j++) {
      cin >> arr[j];
    }

    int firstc, secondc;
    int firstn = 0;
    int secondn = 0;
    int state = 0;

    for (int j = 0; j < n; j++) {
      if (j == 0) {
        firstc = arr[0];
        secondc = arr[n-1];
      }

      if (state == 0) {
        if (arr[j] == firstc) firstn++;
        if (firstn == k) {
          state = 1;
          if (firstc == secondc) {
            state = 2;
            break;
          }
        }
      } else {
        if (arr[j] == secondc) secondn++;
        if (secondn == k) {
          state = 2;
          break;
        }
      }
    }

    if (state == 2) cout << "YES\n";
    else cout << "NO\n";
  }
}
