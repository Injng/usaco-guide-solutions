#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*
  complete search
*/

template<typename C, typename T>
bool contains(C&& c, T e) { 
    return std::find(std::begin(c), std::end(c), e) != std::end(c);
};

void printvector(vector<int> vecto) {
  for (int i = 0; i < vecto.size(); i++) {
    cout << vecto[i] << " ";
  }
  cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> moonies;
  int days[n];
  vector<int> separated;

  for (int i = 0; i < n; i++) {
    cin >> days[i];
  }

  int numos;
  if (n % 2 == 0) {
    numos = n / 2;
  } else {
    numos = (n + 1) / 2;
  }

  moonies.push_back(n * (1 + k));

  for (int i = 1; i < numos + 1; i++) {
    int allperms[n];
    fill(allperms, allperms + n, 1);
    
    for (int j = 0; j < i; j++) {
      allperms[j] = 0;
    }
    
    do {
      int indices[i + 1];
      fill(indices, indices + i + 1, 0);
      int delta[i - 1];
      int counts = 1;
      for (int j = 0; j < n; j++) {
	if (allperms[j] == 0) {
	  indices[counts] = j;
	  // cout << j << "\n";
	  counts++;
	}
      }
      adjacent_difference(indices + 1, indices + i + 1, delta);
      indices[0] = 0;
      if (count(delta, delta + i - 1, 1) == 0 && count(indices + 1, indices + i + 1, 0) == 0) {
	/*
	for (int g = 0; g < i + 1; g++) {
	  cout << indices[g] << " ";
	}
	cout << "\n";
	*/	
	int sum = 0;
	for (int l = 1; l < i + 1; l++) {
	  if (l == 1) {
	    sum = sum + (days[indices[l]] - days[0] + 1) + k;
	  } else {
	    sum = sum + (days[indices[l]] - days[indices[l - 1] + 1]) + k;
	  }
	}
	moonies.push_back(sum);
      }
    } while (next_permutation(allperms, allperms + n));
  }

  // printvector(moonies);

  cout << *min_element(moonies.begin(), moonies.end()) << "\n";
}
