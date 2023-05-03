#include <iostream>
#include <string>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string pass;
  int n;
  string word;
  string teststring;
  cin >> pass >> n;
  string words[n];

  for (int x = 0; x < n; ++x) {
    cin >> word;
    words[x] = word;
  }

  for (int a = 0; a < n; ++a) {
    for (int b = 0; b < n; ++b) {
      teststring = words[a] + words[b];
      if (teststring.find(pass) != string::npos) {
	cout << "YES\n";
	return 0;
      }
    }
  }

  cout << "NO\n";
  return 0;
}
      
  
  
  
