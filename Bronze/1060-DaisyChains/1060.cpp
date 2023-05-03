#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  int flowers[n];
  int count = 0;

  for (int k = 0; k < n; k++) {
    cin >> flowers[k];
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      double sum = 0;

      for (int l = i; l <= j; l++) {
	sum = sum + flowers[l];
      }

      double avg = sum / (j - i + 1);

      for (int l = i; l <= j; l++) {
	if (flowers[l] == avg) {
	  count++;
	  break;
	}
      }
    }
  }

  cout << count << "\n";
}
