#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
 
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("split.in", "r", stdin);
	freopen("split.out", "w", stdout);

  // reading input
	int n;
  cin >> n;
  vector<pair<int, int>> x_values;
  vector<pair<int, int>> y_values;

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    x_values.push_back(make_pair(x, y));
    y_values.push_back(make_pair(x, y));
  }
	
  // sorting
  sort(x_values.begin(), x_values.end(), [] (const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.first < p2.first;
  });
  sort(y_values.begin(), y_values.end(), [] (const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.second < p2.second;
  });

  // calculating minimum area with only one rectangle
  pair<int, int> lower_left = make_pair(x_values[0].first, y_values[0].second);
  pair<int, int> upper_right = make_pair(x_values[n-1].first, y_values[n-1].second);
  int single_area = (upper_right.first - lower_left.first) * (upper_right.second - lower_left.second);

  // calculating prefix sums for max and min
  int curr_max = 0;
  int y_leftmax[n];
  for (int i = 0; i < n; i++) {
    if (x_values[i].second > curr_max) curr_max = x_values[i].second;
    y_leftmax[i] = curr_max;
  }

  curr_max = 0;
  int y_rightmax[n];
  for (int i = n - 1; i >= 0; i--) {
    if (x_values[i].second > curr_max) curr_max = x_values[i].second;
    y_rightmax[i] = curr_max; 
  }

  int curr_min = x_values[0].second;
  int y_leftmin[n];
  for (int i = 0; i < n; i++) {
    if (x_values[i].second < curr_min) curr_min = x_values[i].second;
    y_leftmin[i] = curr_min;
  }

  curr_min = x_values[n-1].second;
  int y_rightmin[n];
  for (int i = n - 1; i >= 0; i--) {
    if (x_values[i].second < curr_min) curr_min = x_values[i].second;
    y_rightmin[i] = curr_min;
  }
  
  curr_max = 0;
  int x_downmax[n];
  for (int i = 0; i < n; i++) {
    if (y_values[i].first > curr_max) curr_max = y_values[i].first;
    x_downmax[i] = curr_max;
  }

  curr_max = 0;
  int x_upmax[n];
  for (int i = n - 1; i >= 0; i--) {
    if (y_values[i].first > curr_max) curr_max = y_values[i].first;
    x_upmax[i] = curr_max;
  }
  
  curr_min = y_values[0].first;
  int x_downmin[n];
  for (int i = 0; i < n; i++) {
    if (y_values[i].first < curr_min) curr_min = y_values[i].first;
    x_downmin[i] = curr_min;
  }

  curr_min = y_values[n-1].first;
  int x_upmin[n];
  for (int i = n - 1; i >= 0; i--) {
    if (y_values[i].first < curr_min) curr_min = y_values[i].first;
    x_upmin[i] = curr_min;
  }

  // Calculate possible areas
  vector<int> areas; 
  areas.push_back(single_area);
  for (int i = 0; i < n - 1; i++) {
    int x = x_values[i].first;
    int y = x_values[i].second;
    if (x_values[i+1].first == x) continue;
    int left_area = (x - x_values[0].first) * (y_leftmax[i] - y_leftmin[i]);
    int right_area = (x_values[n-1].first - x_values[i+1].first) * (y_rightmax[i+1] - y_rightmin[i+1]);
    areas.push_back(left_area + right_area);
  }

  for (int i = 0; i < n; i++) {
    int x = y_values[i].first;
    int y = y_values[i].second;
    if (y_values[i+1].second == y) continue;
    int down_area = (x_downmax[i] - x_downmin[i]) * (y - y_values[0].second);
    int up_area = (x_upmax[i+1] - x_upmin[i+1]) * (y_values[n-1].second - y_values[i+1].second);
    areas.push_back(down_area + up_area);
  }

  cout << single_area - *min_element(areas.begin(), areas.end()) << "\n";
}