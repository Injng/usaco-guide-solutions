#include <iostream>
#include <cstdio>
using namespace std;

void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  setIO("paint");
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  if (c >= a) {
    if (c >= b) {
      cout << (b - a) + (d - c);
    } else {
      if (d <= b) {
	cout << b - a;
      } else if (d > b) {
	cout << d - a;
      }
    }
  } else if (c < a) {
    if (d < a) {
      cout << (b - a) + (d - c);
    } else {
      if (d <= b) {
	cout << b - c;
      } else if (d > b) {
	cout << d - c;
      }
    }
  }
}
    
    
      
    
