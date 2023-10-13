#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cow {
  char dir;
  int x;
  int y;
  int index;
};

int is_intersecting(Cow north_cow, Cow east_cow) {
  int north_x = north_cow.x;
  int north_y = north_cow.y;
  int east_x = east_cow.x;
  int east_y = east_cow.y;
  int intersect_x = north_x;
  int intersect_y = east_y;
  int north_delta = intersect_y - north_y;
  int east_delta = intersect_x - east_x;
  if (north_delta > east_delta) {
    return 1;
  } else if (north_delta < east_delta) {
    return 2;
  } else {
    return 0;
  }
}

int blame[1001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<Cow> north;  
  vector<Cow> east;

  for (int i = 0; i < n; i++) {
    Cow cow;
    cin >> cow.dir >> cow.x >> cow.y;
    cow.index = i;
    if (cow.dir == 'E') east.push_back(cow);
    else if (cow.dir == 'N') north.push_back(cow);
  }

  sort(north.begin(), north.end(), [] (const Cow &c1, const Cow &c2) {
    return c1.x < c2.x;
  });

  sort(east.begin(), east.end(), [] (const Cow &c1, const Cow &c2) {
    return c1.y < c2.y;
  });

  for (int i = 0; i < east.size(); i++) {
    Cow east_cow = east[i];
    for (int j = 0; j < north.size(); j++) {
      Cow north_cow = north[j];
      if (north_cow.dir == 'X' || north_cow.y > east_cow.y || north_cow.x < east_cow.x) {
        continue;
      }
      int result = is_intersecting(north_cow, east_cow); 
      if (result == 1) {
        north_cow.dir = 'X';
        blame[east_cow.index] += 1 + blame[north_cow.index];
      } else if (result == 2) {
        blame[north_cow.index] += 1 + blame[east_cow.index];
        break;
      } else {
        continue;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << blame[i] << "\n";
  }
}

