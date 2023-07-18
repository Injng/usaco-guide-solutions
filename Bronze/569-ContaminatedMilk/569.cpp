#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("badmilk.in", "r", stdin);
  freopen("badmilk.out", "w", stdout);

  int n, m, d, s;
  cin >> n >> m >> d >> s;
  map<int, vector<pair<int, int>>> transcript;
  vector<set<int>> allMilk;
  vector<int> doses;
  
  for (int i = 0; i < d; i++) {
    int p, m, t;
    cin >> p >> m >> t;
    pair drank = make_pair(m, t);
    transcript[p].push_back(drank);
  }

  for (int i = 0; i < s; i++) {
    int p, t;
    cin >> p >> t;
    set<int> milk;

    for (const auto& j : transcript[p]) {
      if (j.second < t) {
	milk.insert(j.first);
      }
    }

    allMilk.push_back(milk);
  }

  set<int> common;
  for (int i = 0; i < allMilk.size(); i++) {
    set<int> next;
    if (i == 0) {
      for (const auto& j : allMilk[0]) {
	if (allMilk[1].find(j) != allMilk[1].end()) {
	  common.insert(j);
	}
      }
    } else {
      for (const auto& j : common) {
	if (allMilk[i].find(j) != allMilk[i].end()) {
	  next.insert(j);
	}
      }
      common = next;
    }
  }
	
  for (const auto& i : common) {
    int doseNum = 0;
    for (const auto& j : transcript) {
      for (int k = 0; k < j.second.size(); k++) {
	if (j.second[k].first == i) {
	  doseNum++;
	  break;
	}
      }
    }
    doses.push_back(doseNum);
  }

  cout << *max_element(doses.begin(), doses.end()) << "\n";
}
