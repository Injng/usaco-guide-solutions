#include <iostream>
#include <string>

using namespace std;

void setIO(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
  setIO("traffic");
  int n;
  cin >> n;
  int data[n][3];
  string temp;
  int traffic[2] = {0, 0};
  bool priornones = false;

  for (int i = 0; i < n; i++) {
    cin >> temp;
    if (temp == "on") data[i][0] = 1;
    if (temp == "off") data[i][0] = -1;
    if (temp == "none") data[i][0] = 0;
    cin >> data[i][1] >> data[i][2];
  }

  // Scanning from right to left
  for (int r = n - 1; r >= 0; r--) {
    if (data[r][0] == -1) {
      traffic[0] = traffic[0] + data[r][1];
      traffic[1] = traffic[1] + data[r][2];
    } else if (data[r][0] == 1) {
      traffic[0] = traffic[0] - data[r][2];
      traffic[1] = traffic[1] - data[r][1];
    } else {
      if (priornones == false) {
	traffic[0] = data[r][1];
	traffic[1] = data[r][2];
	priornones = true;
      } else {
	traffic[0] = max(traffic[0], data[r][1]);
	traffic[1] = min(traffic[1], data[r][2]);
      }
    }
  }

  cout << traffic[0] << " " << traffic[1] << "\n";
  traffic[0] = 0;
  traffic[1] = 0;
  priornones = false;

  // Scanning from left to right
  for (int l = 0; l < n; l++) {
    if (data[l][0] == 1) {
      traffic[0] = traffic[0] + data[l][1];
      traffic[1] = traffic[1] + data[l][2];
    } else if (data[l][0] == -1) {
      traffic[0] = traffic[0] - data[l][2];
      traffic[1] = traffic[1] - data[l][1];
    } else {
      if (priornones == false) {
	traffic[0] = data[l][1];
	traffic[1] = data[l][2];
	priornones = true;
      } else {
	traffic[0] = max(traffic[0], data[l][1]);
	traffic[1] = min(traffic[1], data[l][2]);
      }
    }
  }

  cout << traffic[0] << " " << traffic[1] << "\n";  
}
