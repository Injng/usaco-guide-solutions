#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<char> > rotations(vector<vector<char> > stamp) {
  int length = stamp.size();
  vector<vector<char> > rotated(length);
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      rotated[i].push_back(stamp[length - 1 - j][i]);
    }
  }
  return rotated;
}

int check(vector<vector<char> > map, vector<vector<char> > stamp) {
  int length = map.size();
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      if (map[i][j] == '.' && stamp[i][j] == '*') {
	return 1;
      }
    }
  }
  return 0;
}

/*
  1. Read input
  2. Generate  all 4 possible rotations
  3. Search over all possible stamping patterns, set 1 when not possible
  4. If no 1, therefore possible
*/

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<vector<char> > map;
    vector<vector<char> > stamp;
    int checks[n][n];
    fill(checks[0], checks[0] + n * n, 1);
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    
    for (int j = 0; j < n; j++) {
      string line;
      getline(cin, line);
      vector<char> ink(line.begin(), line.end());
      map.push_back(ink);
    }

    int k;
    cin >> k;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

    for (int j = 0; j < k; j++) {
      string line;
      getline(cin, line);
      vector<char> sink(line.begin(), line.end()); // stamp ink
      stamp.push_back(sink);
    }
    
    int slength = stamp.size();
    int mlength = map.size();
    vector<vector<char> > a = rotations(stamp);
    vector<vector<char> > b = rotations(a);
    vector<vector<char> > c = rotations(b);

    for (int bb = 0; bb < mlength; bb++) {
      for (int cc = 0; cc < mlength; cc++) {
	if (map[bb][cc] == '.') {
	  checks[bb][cc] = 0;
	}
      }
    }

    for (int x = 0; x <= mlength - slength; x++) {
      for (int y = 0; y <= mlength - slength; y++) {
	vector<vector<char> > sub(slength);
	
	for (int v = x; v < x + slength; v++) {
	  for (int w = y; w < y + slength; w++) {
	    sub[v - x].push_back(map[v][w]);
	  }
	}
	if (check(sub, stamp) == 1 && check(sub, a) == 1 && check(sub, b) == 1 && check(sub, c) == 1) {
	  for (int aa = x; aa < x + slength; aa++) {
	    for (int ab = y; ab < y + slength; ab++) {
	      if (map[aa][ab] == '*' && checks[aa][ab] != 0) {
		checks[aa][ab] = 1;
	      } else if (map[aa][ab] == '.') {
		checks[aa][ab] = 0;
	      }
	    }
	  }
	} else {
	    for (int aa = x; aa < x + slength; aa++) {
	      for (int ab = y; ab < y + slength; ab++) {
	        if (map[aa][ab] == '*') {
		  checks[aa][ab] = 0;
		} else if (map[aa][ab] == '.') {
		  checks[aa][ab] = 0;
		}
	      }
	    }
	}
      }
    }

    if (count(checks[0], checks[0] + n * n, 1) == 0) {
      cout << "YES\n";
    } else {
      cout  << "NO\n";
    }
  }
}
  
  




/*

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    vector<vector<char> > map;
    vector<vector<char> > stamp;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    
    for (int j = 0; j < n; j++) {
      string line;
      getline(cin, line);
      vector<char> ink(line.begin(), line.end());
      map.push_back(ink);
    }

    int k;
    cin >> k;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

    for (int j = 0; j < k; j++) {
      string line;
      getline(cin, line);
      vector<char> sink(line.begin(), line.end()); // stamp ink
      stamp.push_back(sink);
    }
    
    int slength = stamp.size();
    int mlength = map.size();
    vector<vector<char> > a = rotations(stamp);
    vector<vector<char> > b = rotations(a);
    vector<vector<char> > c = rotations(b);

    for (int x = 0; x <= mlength - slength; x++) {
      for (int y = 0; y <= mlength - slength; y++) {
	vector<vector<char> > sub(slength);
	
	for (int v = x; v < x + slength; v++) {
	  for (int w = y; w < y + slength; w++) {
	    sub[v - x].push_back(map[v][w]);
	  }
	}

	if (check(sub, stamp) == 1 && check(sub, a) == 1 && check(sub, b) == 1 && check(sub, c) == 1) {
	  cout << "NO\n";
	  goto stop;
	}
      }
    }
    cout << "YES\n";
  stop: continue;
  }
}

*/
