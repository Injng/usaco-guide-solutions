#include <iostream>
#include <algorithm>

using namespace std;

/*
  Simulation
*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  // Read input
  int n, t;
  cin >> n >> t;
  long long haybales[t];
  long long deliveries[n][2];
  fill(haybales, haybales + t, 0);

  for (int i = 0; i < n; i++) {
    cin >> deliveries[i][0] >> deliveries[i][1];
  }
  
  for (int i = 0; i < n; i++) {
    if (i == n - 1) {
      long long d, b, e;
      d = deliveries[i][0];
      b = deliveries[i][1];
      e = t;
      for (int j = d - 1; j < e; j++) {
	if ((haybales[j] + b - (j - d + 1)) < 0) { // No negatives
	  break;
	}
        haybales[j] = haybales[j] + b - (j - d + 1);  // As j increases by 1, haybales decreases by 1
      }
    } else {
      long long d, b;
      long long e; //for the next iteration
      d = deliveries[i][0];
      b = deliveries[i][1];
      e = deliveries[i + 1][0];
      for (int j = d - 1; j < e; j++) {
	if ((haybales[j] + b - (j - d + 1)) < 0) { // No negatives
	  break;
	}
        haybales[j] = haybales[j] + b - (j - d + 1);  // As j increases by 1, haybales decreases by 1
      }
    }
  }

  cout << t - count(haybales, haybales + t, 0) << "\n";
} 
