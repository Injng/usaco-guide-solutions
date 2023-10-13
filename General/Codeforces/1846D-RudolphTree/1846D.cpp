#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    double d, h;
    cin >> n >> d >> h;
    double heights[n];

    for (int j = 0; j < n; j++) {
      cin >> heights[j];
    }

    double each = (d * h) / 2;
    double area = each * n;

    for (int j = 0; j < n - 1; j++) {
      if (heights[j] + h > heights[j+1]) {
	double delta = heights[j+1] - heights[j];
	double in = h - delta;
	double base = d * (in / h);
	double overlap = (base * in) / 2;
	area -= overlap;
      }
    }

    cout << setprecision(15) << area << "\n";
  }
}
