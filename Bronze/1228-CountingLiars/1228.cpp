#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

/*
Complete search solution, checking each cow.
1) Assume one of the cows is telling the truth
2) All cows on one side must be either G or L
3) ALl cows on the other side can be either G or L
4) Count
*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, char> > tcows;
  vector<int> counts;
  char cows[n];

  // Read into vector

  for (int i = 0; i < n; i++) {
    char location;
    int p;
    cin >> location >> p;
    pair<int, char> cow(p, location);
    tcows.push_back(cow);
  }

  sort(tcows.begin(), tcows.end());

  // Extract chars into array

  for (int i = 0; i < n; i++) {
    cows[i] = tcows[i].second;
  }

  // Enumerate over each cow and assume each is telling the truth

  for (int j = 0; j < n; j++) {
    int count = 0;
    if (cows[j] == 'L') {
      if (j == n - 1) {
	count = count;
      } else {
	for (int k = j + 1; k < n; k++) {
	  if (cows[k] == 'G') {
	    count++;
	  }
	}
      }

      if (j == 0) {
	count = count;
      } else {
	int countl = 0;
	int countg = 0;
	for (int k = j - 1; k >= 0; k--) {
	  if (cows[k] == 'L') {
	    countl++;
	  } else if (cows[k] == 'G') {
	    countg++;
	  }
	}

	count = count + min(countl, countg);
      }	  
    } else if (cows[j] == 'G') {
      if (j == n - 1) {
	count = count;
      } else {
	int countl = 0;
	int countg = 0;
	for (int k = j + 1; k < n; k++) {
	  if (cows[k] == 'L') {
	    countl++;
	  } else if (cows[k] == 'G') {
	    countg++;
	  }
	}

	count = count + min(countl, countg);
      }

      if (j == 0) {
	count = count;
      } else {
	for (int k = j - 1; k >= 0; k--) {
	  if (cows[k] == 'L') {
	    count++;
	  }
	}
      }
    }

    counts.push_back(count);
  }

  cout << *min_element(counts.begin(), counts.end()) << "\n";
}
  
