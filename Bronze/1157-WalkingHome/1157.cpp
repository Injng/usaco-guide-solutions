#include <iostream>
#include <vector>

using namespace std;

int paths(char prevchange, char change, int turns, int x, int y, int n, int k, vector<vector<char> > map) {
    if (change != prevchange) {
        turns++;
    }

    if (turns == k) {
        return 0;
    } else if (x == n - 1 && y == n - 1) {
        return 1;
    }

    if (map[x][y] == 'H') {
        return 0;
    } else if (prevchange == 'a') {
        return paths('x', 'x', turns, x + 1, y, n, k, map) + paths('y', 'y', turns, x + 1, y, n, k, map);
    } else if (map[x][y] == '.') {
        return paths(change, 'x', turns, x + 1, y, n, k, map) + paths(change, 'y', turns, x, y + 1, n, k, map);
    }
}

int main() {
    int t;
    int n, k;
    char in;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        vector<vector<char> > map;
        vector<char> temp;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                cin >> in;
                temp.push_back(in);
            }

            map.push_back(temp);
            temp = {}; // delete values in vector??
        }
        
        cout << paths('a', 'a', 0, 0, 0, n, k, map) << "\n";
        map = {{}};
    }
}



