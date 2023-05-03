#include <iostream>
using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int inarr[n];
  for (int i = 0; i < n; i++) {
    cin >> inarr[i];
  }

  int currentnum;
  int moves = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0) currentnum = inarr[0];
    if (inarr[i] < currentnum) {
      moves = moves + currentnum - inarr[i];
    } else {
      currentnum = inarr[i];
    }
  }

  cout << moves << "\n";
}      
