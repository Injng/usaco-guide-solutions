#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<pair<int, int>> colors[9];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);

    int n;
    cin >> n;
    string canvas[n];
    for (int i = 0; i < n; i++) cin >> canvas[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int color = canvas[i][j] - '0';
            if (color == 0) continue;
            colors[color - 1].emplace_back(i, j);
        }
    }

    int count = 0;
    vector<int> added;
    vector<int> bounds[9];
    for (int i = 0; i < 9; i++) {
        if (colors[i].size() == 0) continue;

        int min_x = get<0>(*min_element(colors[i].begin(), colors[i].end(), [](auto p1, auto p2) {
            return get<0>(p1) < get<0>(p2);
        }));
        int min_y = get<1>(*min_element(colors[i].begin(), colors[i].end(), [](auto p1, auto p2) {
            return get<1>(p1) < get<1>(p2);
        }));
        int max_x = get<0>(*max_element(colors[i].begin(), colors[i].end(), [](auto p1, auto p2) {
            return get<0>(p1) < get<0>(p2);
        }));
        int max_y = get<1>(*max_element(colors[i].begin(), colors[i].end(), [](auto p1, auto p2) {
            return get<1>(p1) < get<1>(p2);
        }));

        bounds[i].push_back(min_x);
        bounds[i].push_back(min_y);
        bounds[i].push_back(max_x);
        bounds[i].push_back(max_y);
    }

    // iterate through all colors in bounds, for each pair of colors, check if the second color is in the bounds of the first color. If it is, add one to the count and add the first color to added. If the second color is already in added, remove it from added and subtract one from the count.
    for (int i = 0; i < 9; i++) {
        if (bounds[i].size() == 0) continue;
        for (int j = 0; j < 9; j++) {
            if (bounds[j].size() == 0 || i == j) continue;
            if (bounds[i][0] <= bounds[j][0] && bounds[i][1] <= bounds[j][1] && bounds[i][2] >= bounds[j][2] && bounds[i][3] >= bounds[j][3]) {
                if (find(added.begin(), added.end(), j) == added.end()) {
                    count++;
                    added.push_back(j);
                }
            } else if (find(added.begin(), added.end(), j) != added.end()) {
                count--;
                added.erase(find(added.begin(), added.end(), j));
            }
        }
    }


    cout << count << "\n";
}