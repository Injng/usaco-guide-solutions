#include <iostream>
#include <algorithm>

using namespace std;

void swapity(int sequence[], int a, int b) {
  int sublength = b - a + 1;
  int tempseq[sublength];
  int index = b - a;

  for (int i = a - 1; i < b; i++) {
    tempseq[index] = sequence[i];
    index--;
  }

  for (int i = a - 1; i < b; i++) {
    sequence[i] = tempseq[i - a + 1];
  }
}
  
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("swap.in", "r", stdin);
  freopen("swap.out", "w", stdout);

  int n, k;
  cin >> n >> k;
  int sequence[n];
  int orig[n];

  for (int i = 0; i < n; i++) {
    sequence[i] =  i + 1;
    orig[i] = i + 1;
  }

  int a1, a2, b1, b2;
  cin >> a1 >> a2 >> b1 >> b2;
  int cycle = 0;

  for (int i = 0; i < k; i++) {
    swapity(sequence, a1, a2);
    swapity(sequence, b1, b2);
    if (equal(sequence, sequence+n, orig)) {
      cycle = i + 1;
      break;
    } 
  }

  if (cycle != 0) {
    int remaining = k % cycle;
    for (int i = 0; i < remaining; i++) {
      swapity(sequence, a1, a2);
      swapity(sequence, b1, b2);
    }
  }
  
  for (int i = 0; i < n; i++) {
    cout << sequence[i] << "\n";
  }
}