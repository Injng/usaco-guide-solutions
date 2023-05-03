#include <iostream>
#include <string>
#include <vector>

using namespace std;

void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setIO("blocks");
  int n;
  string a;
  string b;
  int alphanumber;
  cin >> n;
  
  int frontalphabet[26];
  int backalphabet[26];
  int alphabet[26];
  fill_n(frontalphabet, 26, 0);
  fill_n(backalphabet, 26, 0);
  fill_n(alphabet, 26, 0);

  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    
    for (int g = 0; g < a.length(); g++) {
      alphanumber = a[g];
      frontalphabet[alphanumber - 97] += 1;
    }

    for (int h = 0; h < b.length(); h++) {
      alphanumber = b[h];
      backalphabet[alphanumber - 97] += 1;
    }

    for (int l = 0; l < 26; l++) {
      alphabet[l] += max(frontalphabet[l], backalphabet[l]);
    }
    
    fill_n(frontalphabet, 26, 0);
    fill_n(backalphabet, 26, 0);
  }

  for (int z = 0; z < 26; z++) {
    cout << alphabet[z] << "\n";
  }
}
    
