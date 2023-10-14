#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> farthest_rooms;
        for (int i = 0; i < n; i++) {
            double d, s;
            cin >> d >> s;
            farthest_rooms.push_back(d + ceil(s / 2) - 1);
        }
        cout << *min_element(farthest_rooms.begin(), farthest_rooms.end()) << "\n";
    }
}