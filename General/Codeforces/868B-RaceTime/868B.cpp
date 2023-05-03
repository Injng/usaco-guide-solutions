#include <iostream>
using namespace std;

// Function for while loops

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  double h;
  double m;
  double s;
  double t1;
  double t2;

  cin >> h >> m >> s >> t1 >> t2;

  h = (h / 12) * 60;
  t1 = (t1 / 12) * 60;
  t2 = (t2 / 12) * 60;

  int clockwise = t1;
  if (clockwise == 60) clockwise = 0;
  int counterwise = t1;
  if (counterwise == 0) counterwise = 60;
  
  while (clockwise != t2) {
    if (clockwise == 60) clockwise = 0;
    ++clockwise;
    if (clockwise == 60) clockwise = 0;
    if (clockwise != t1) {
      if (clockwise == h || clockwise == h - 60) {
        break;
      } else if (clockwise == m || clockwise == m - 60) {
        break;
      } else if (clockwise == s || clockwise == s - 60) {
        break;
      } else if (clockwise == t2) {
        cout << "YES\n";
        return 0;
      } else {
        continue;
      }
    } else {
      continue;
    }
  }

  while (counterwise != t2) {
    if (counterwise == 0) counterwise = 60;
    --counterwise;
    if (counterwise == 0) counterwise = 60;
    if (counterwise != t1) {
      if (counterwise == h) {
        break;
      } else if (counterwise == m || counterwise == m + 60) {
        break;
      } else if (counterwise == s || counterwise == s + 60) {
        break;
      } else if (counterwise == t2) {
        cout << "YES\n";
        return 0;
      } else {
        continue;
      }
    } else {
      continue;
    } 
  }

  cout << "NO\n";
}
       
    

