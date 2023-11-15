#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<bool> is_visited;
vector<int> cows;
vector<int> x_val;
vector<int> y_val;

void dfs(int i) {
    if (is_visited[i]) return;
    else is_visited[i] = true;
    cows.push_back(i);
    for (int cow : adj[i]) {
        dfs(cow);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    adj.resize(n);
    is_visited.resize(n);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x_val.push_back(x);
        y_val.push_back(y);
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    vector<int> perimeters;
    for (int i = 0; i < n; i++) {
        vector<int> x;
        vector<int> y;
        if (is_visited[i]) continue;
        else dfs(i);
        for (int cow : cows) {
            x.push_back(x_val[cow]);
            y.push_back(y_val[cow]);
        }
        cows.clear();

        int min_x = *min_element(x.begin(), x.end());
        int max_x = *max_element(x.begin(), x.end());
        int min_y = *min_element(y.begin(), y.end());
        int max_y = *max_element(y.begin(), y.end());
        perimeters.push_back(2 * (max_x - min_x + max_y - min_y));
    }

    cout << *min_element(perimeters.begin(), perimeters.end()) << '\n';
}