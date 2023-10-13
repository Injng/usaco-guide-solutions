#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("triangles.in", "r", stdin);
  freopen("triangles.out", "w", stdout);

  int n;
  cin >> n;
  vector<pair<int, int>> posts;
  vector<int> areas;

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    pair point = make_pair(x, y);
    posts.push_back(point);
  }

  for (int i = 0; i < n - 2; i++) {
    pair firstPoint = posts[i];
    for (int j = i + 1; j < n - 1; j++) {
      pair secondPoint = posts[j];
      for (int k = j + 1; k < n; k++) {
	pair thirdPoint = posts[k];
	int vertical;
	int horizontal;
	// Make sure for one vertical
	if (firstPoint.first != secondPoint.first) {
	  if (firstPoint.first != thirdPoint.first) {
	    if (secondPoint.first != thirdPoint.first) {
	      continue;
	    }
	  }
	}
	// Make sure for one horizontal
	if (firstPoint.second != secondPoint.second) {
	  if (firstPoint.second != thirdPoint.second) {
	    if (secondPoint.second != thirdPoint.second) {
	      continue;
	    }
	  }
	}
	// Make sure three points are not colinear
	if (firstPoint.first == secondPoint.first && firstPoint.first == thirdPoint.first) {
	  continue;
	} else if (firstPoint.second == secondPoint.second && firstPoint.second == thirdPoint.second) {
	  continue;
	}
	// Calculate area
	if (firstPoint.first == secondPoint.first) {
	  vertical = abs(firstPoint.second - secondPoint.second);
	} else if (firstPoint.first == thirdPoint.first) {
	  vertical = abs(firstPoint.second - thirdPoint.second);
	} else if (secondPoint.first == thirdPoint.first) {
	  vertical = abs(secondPoint.second - thirdPoint.second);
	} else {
	  cout << "Error\n";
	}
	if (firstPoint.second == secondPoint.second) {
	  horizontal = abs(firstPoint.first - secondPoint.first);
	} else if (firstPoint.second == thirdPoint.second) {
	  horizontal = abs(firstPoint.first - thirdPoint.first);
	} else if (secondPoint.second == thirdPoint.second) {
	  horizontal = abs(secondPoint.first - thirdPoint.first);
	} else {
	  cout << "Error\n";
	}
	areas.push_back(vertical * horizontal);
      }
    }
  }

  cout << *max_element(areas.begin(), areas.end()) << "\n";
}
