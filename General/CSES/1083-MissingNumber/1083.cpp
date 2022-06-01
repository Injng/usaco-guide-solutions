c#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n;
  cin >> n;
  long long sum = 0;
  long long temp;
  for (int i = 0; i < n - 1; ++i)
  {
    cin >> temp;
    sum += temp;
  }

  cout << ((n * (n + 1)) / 2) - sum << "\n";
} 
