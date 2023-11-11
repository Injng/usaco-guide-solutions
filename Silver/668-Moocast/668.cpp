#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> is_visited;

int cow_count = 0;

int distance(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void dfs(int i) {
    if (is_visited[i]) return;
    else is_visited[i] = true;
    cow_count++;
    for (int city : adj[i]) {
        dfs(city);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);

    int n;
    cin >> n;
    adj.resize(n);
    is_visited.resize(n);

    vector<vector<int>> cows;
    for (int i = 0; i < n; i++) {
        int x, y, p;
        cin >> x >> y >> p;
        cows.push_back({x, y, p});
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (distance(cows[i][0], cows[i][1], cows[j][0], cows[j][1]) <= cows[i][2] * cows[i][2]) {
                adj[i].push_back(j);
            }
        }
    }

    int max = 0;
    for (int i = 0; i < n; i++) {
        dfs(i);
        max = max < cow_count ? cow_count : max;
        cow_count = 0;
        for (int j = 0; j < n; j++) {
            is_visited[j] = false;
        }
    }

    cout << max << "\n";
}