#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

void prtvector(vector<int> vec) {
  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
    cout << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> nums;
  for (int i = 0; i < n; i++) {
    nums.push_back(i + 1);
  }

  vector<vector<int> > permute;
  do {
    permute.push_back(nums);
  } while (next_permutation(nums.begin(), nums.end()));

  for (int i = 0; i < permute.size(); i++) {
    for (int j = 1; j < permute[i].size(); j++) {
      vector<int> permutation = permute[i];
      if (abs(permutation[j] - permutation[j - 1]) > 1) {
	if (j == permute[i].size() - 1) {
	  prtvector(permute[i]);
	  return 0;
	}
      } else {
	break;
      }
    }
  }

  cout << "NO SOLUTION\n";
}
	 
	
    
