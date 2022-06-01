#include <iostream>

using namespace std;

void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setIO("shuffle");
    
  int n;
  cin >> n;

  int shuffles[n];
  int tempshuffles[n];
  int ids[n];

  for (int i = 0; i < n; i++) {
    cin >> shuffles[i];
  }

  for (int j = 0; j < n; j++) {
    cin >> ids[j];
  }

  for (int y = 0; y < 3; y++) {
    for (int x = 0; x < n; x++) {
      tempshuffles[x] = ids[shuffles[x] - 1];
    }
    std::fill_n(ids, n, 0);
    for (int z = 0; z < n; z++) {
      ids[z] = tempshuffles[z];
    }
    std::fill_n(tempshuffles, n, 0);
  }

  for (int m = 0; m < n; m++) {
    cout << ids[m] << "\n";
  }
}
