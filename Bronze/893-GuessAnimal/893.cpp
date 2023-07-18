#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("guess.in", "r", stdin);
  freopen("guess.out", "w", stdout);

  int n;
  cin >> n;
  map<string, set<string>> characteristics;
  vector<string> animals;
  vector<int> questions;

  for (int i = 0; i < n; i++) {
    string animal;
    cin >> animal;
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      string characteristic;
      cin >> characteristic;
      characteristics[animal].insert(characteristic);
    }
  }

  for (const auto& i : characteristics) {
    animals.push_back(i.first);
  }

  for (int i = 0; i < animals.size() - 1; i++) {
    for (int j = i + 1; j < animals.size(); j++) {
      int common = 1;
      for (const auto& k : characteristics[animals[i]]) {
	if (characteristics[animals[j]].find(k) != characteristics[animals[j]].end()) {
	  common++;
	}
      }
      questions.push_back(common);
    }
  }

  cout << *max_element(questions.begin(), questions.end()) << "\n";
}
