#include <iostream>
#include <string>

using namespace std;

void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setIO("cownomics");
  int n;
  int m;
  int exit = 0;
  int count = 0;
  int total = 0;
  cin >> n >> m;

  string spotty[n];
  string plain[n];

  for (int i = 0; i < n; i++) {
    cin >> spotty[n];
  }

  for (int k = 0; k < n; k++) {
    cin >> plain[n];
  }

  for (int position = 0; position < m; position++) {
    for (int q = 0; q < n; q++) {
      if (exit != 0) {
	exit = 0;
	break;
      }
      
      for (int r = 0; r < n; r++) {
	if (plain[r].find(spotty[q][position]) >= 1) {
	  exit = 1;
	  break;
	} else {
	  continue;
	}
      }

      count++;
    }

    if (count == 3) {
      total++;
    }
  }

  cout << total << "\n";
} 
