#include <iostream>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    int a = n - 1;
    int status = 0;

    cin >> n;

    if (a <= 2) {
      cout << "NO\n";
      continue;
    }

    for (int k = 0; k < n; k++) {
      int lo = -1;
      int hi = n;

      while(hi - lo > 1) {
	int mid = (hi - lo) >> 1;
	double calc = (pow(k, mid) - 1) / (k - 1);
	double da = a;
	
	if (fmod(calc, 1) == 0) {
	  int comp = calc;
	  if (comp == a) {
	    status = 1;
	    break;
	  }
	}

	if (da > a) hi = mid;
	else lo = mid;
      }

      if (status == 1) {
	cout << "YES\n";
	break;
      }
    }

    if (status == 0) {
      cout << "NO\n";
      break;
    }
  }
}
