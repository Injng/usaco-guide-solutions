#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
  
int main() {
  string letters;
  cin >> letters;
  vector<string> permutations;
  sort(letters.begin(), letters.end());

  do {
    permutations.push_back(letters);
  } while (next_permutation(letters.begin(), letters.end()));

  cout << permutations.size() << "\n";
  for (int i = 0; i < permutations.size(); i++) {
    cout << permutations[i] << "\n";
  }
}

