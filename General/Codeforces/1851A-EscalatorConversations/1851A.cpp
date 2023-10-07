#include <iostream>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n, m, k, H;
    cin >> n >> m >> k >> H;
    int num = 0;
    
    for (int j = 0; j < n; j++) {
      int person;
      cin >> person;
      if (abs(H - person) % k == 0 && abs(H - person) / k < m && abs(H - person) / k > 0) num++; 
    }

    cout << num << "\n";
  }
}
