#include <iostream>
#include <algorithm>

using namespace std;
  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n, k;
  cin >> n >> k;
  int sizes[n];
  int diamonds[n];

  for (int i = 0; i < n; i++) {
    cin >> sizes[i];
  }

  for (int j = 0; j < n; j++) {
    int counta = 0;
    int countb = 0;
    int size = sizes[j];

    for (int l = 0; l < n; l++) {
      if (sizes[l] >= size && sizes[l] <= (size + k)) {
	counta++;
      }
      if (sizes[l] <= size && sizes[l] >= (size - k)) {
	countb++;
      }
    }
    diamonds[2*j] = counta;
    diamonds[2*j+1] = countb;
  }

  cout << *max_element(diamonds, diamonds + 2*n) << "\n";
}
