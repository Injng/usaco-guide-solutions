#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int q;
    cin >> q;
    int ascending = 0;
    int previous;
    cin >> previous;
    int first = previous;
    if (q == 1) {
      cout << "1\n";
      continue;
    }
    cout << 1;
    for (int j = 1; j < q; j++) {
      int current;
      cin >> current;
      if (current >= previous) {
	if (ascending == 1) {
	  if (first >= current) {
	    previous = current;
	    cout << 1;
	    continue;
	  } else {
	    cout << 0;
	    continue;
	  }
	} else {
	  previous = current;
	  cout << 1;
	  continue;
	}
      } else {
	ascending++;
	if (ascending == 1) {
	  if (first >= current) {
	    previous = current;
	    cout << 1;
	    continue;
	  } else {
	    cout << 0;
	    ascending--;
	    continue;
	  }
	} else {
	  cout << 0;
	  ascending--;
	  continue;
	}
      }
    }
    cout << "\n";
  }
}
      
    
