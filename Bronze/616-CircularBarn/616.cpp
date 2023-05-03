#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setIO("cbarn");
  vector<int> distances;
  int n;
  cin >> n;
  int rooms[n];
  int roomnum = 1;
  int sum = 0;

  for (int i = 0; i < n; i++) {
    cin >> rooms[i];
  }

  for (int r = 1; r <= n; r++) {
    roomnum = 1;
    sum = 0;
    while (roomnum < 1 + n) {
      sum += rooms[(r + roomnum - 2) % n] * ((roomnum - 1) % n);
      roomnum++;
    }
    distances.push_back(sum);
  }

  cout << *min_element(distances.begin(), distances.end());
}

  
