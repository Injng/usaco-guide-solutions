#include <iostream>

using namespace std;

int main() {
  // give N numbers
  int n;
  cin >> n;
  // give goal S
  int s;
  cin >> s;
  int numbers[n];
  // read N numbers into array
  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
  }

  for (int mask = 0; mask < (1 << n); mask++) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
      if (mask & (1 << j)) {
	sum += numbers[j];
      }
    }

    if (sum == s) cout << "Yes";
  }
}
