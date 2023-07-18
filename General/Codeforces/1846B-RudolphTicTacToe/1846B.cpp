#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int j = 0; j < t; j++) {
    char a, b, c, d, e, f, g, h, i;
    string row1, row2, row3;
    cin >> row1 >> row2 >> row3;

    a = row1[0];
    b = row1[1];
    c = row1[2];
    d = row2[0];
    e = row2[1];
    f = row2[2];
    g = row3[0];
    h = row3[1];
    i = row3[2];

    set<char> r1;
    set<char> r2;
    set<char> r3;
    set<char> c1;
    set<char> c2;
    set<char> c3;
    set<char> d1;
    set<char> d2;

    r1.insert(a);
    r1.insert(b);
    r1.insert(c);

    r2.insert(d);
    r2.insert(e);
    r2.insert(f);

    r3.insert(g);
    r3.insert(h);
    r3.insert(i);

    c1.insert(a);
    c1.insert(d);
    c1.insert(g);

    c2.insert(b);
    c2.insert(e);
    c2.insert(h);

    c3.insert(c);
    c3.insert(f);
    c3.insert(i);

    d1.insert(a);
    d1.insert(e);
    d1.insert(i);

    d2.insert(c);
    d2.insert(e);
    d2.insert(g);

    if (r1.size() == 1 && a != '.') {
      cout << a << "\n";
    } else if (r2.size() == 1 && d != '.') {
      cout << d << "\n";
    } else if (r3.size() == 1 && g != '.') {
      cout << g << "\n";
    } else if (c1.size() == 1 && a != '.') {
      cout << a << "\n";
    } else if (c2.size() == 1 && b != '.') {
      cout << b << "\n";
    } else if (c3.size() == 1 && c != '.') {
      cout << c << "\n";
    } else if (d1.size() == 1 && a != '.') {
      cout << a << "\n";
    } else if (d2.size() == 1 && c != '.') {
      cout << c << "\n";
    } else {
      cout << "DRAW\n";
    }
  }
}
