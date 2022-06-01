#include <iostream>
#include <cstdio>

using namespace std;

void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setIO("paint");
  
  int a;
  int b;
  int c;
  int d;

  cin >> a >> b;
  cin >> c >> d;

  if (c < a) {
    if (d < a) {
      cout << d - c + b - a << "\n";
    } else if (d >= b) {
      cout << d - c << "\n";
    } else if (d >= a && d < b) {
      cout << b - c << "\n";
    }
  } else if (c >= b) {
    cout << d - c + b - a << "\n";
  } else if (c >= a && c < b) {
    if (d < b) {
      cout << b - a << "\n";
    } else if (d >= b) {
      cout << d - a << "\n";
    }
  }
}

