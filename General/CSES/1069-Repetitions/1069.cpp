#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> lengths;
  char currentchar;
  int length = 0;

  string dna;
  cin >> dna;
  

  for (int x = 0; x < dna.length(); x++) {
    if (x == 0) {
      currentchar = dna[0];
    } else {
      if (dna[x] == currentchar) {
	length++;
      } else {
	lengths.push_back(length);
	length = 0;
	currentchar = dna[x];
      }
    }
  }

  double max = *max_element(lengths.begin(), lengths.end());
  cout << max + 1 << "/n";
}
