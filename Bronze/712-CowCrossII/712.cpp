#include <iostream>
#include <string>

using namespace std;

int main() {
  string locations;
  cin >> locations;
  string templocations = locations;
  char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

  int entry1;
  int entry2;
  int exit1;
  int exit2;
  int count = 0;

  for (int i = 0; i < 25; i++) {
    for (int j = i + 1; j < 26; j++) {
      entry1 = locations.find(alphabet[i]);
      entry2 = locations.find(alphabet[j]);
      templocations[entry1] = ' ';
      templocations[entry2] = ' ';
      exit1 = templocations.find(alphabet[i]);
      exit2 = templocations.find(alphabet[j]);
      templocations = locations;
      if (entry1 < entry2) {
	if (exit1 > entry2 && exit1 < exit2) {
	  count++;
	} else {
	  continue;
	}
      } else if (entry2 < entry1) {
	if (exit2 > entry1 && exit2 < exit1) {
	  count++;
	} else {
	  continue;
	}
      } else {
	count++;
      }
    }
  }

  cout << count << "\n";
}
