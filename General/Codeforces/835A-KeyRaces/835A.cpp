#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int s, v1, v2, t1, t2;
  cin >> s >> v1 >> v2 >> t1 >> t2;

  int total1 = v1 * s + 2 * t1;
  int total2 = v2 * s + 2 * t2;

  if (total1 == total2) cout << "Friendship";
  else if (total1 >= total2) cout << "First";
  else cout << "Second";
}
