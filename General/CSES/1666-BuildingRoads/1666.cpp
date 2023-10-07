#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> is_visited;

void dfs(int i) {
    if (is_visited[i]) return;
    else is_visited[i] = true;
    for (int city : adj[i]) {
        dfs(city);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    adj.resize(n);
    is_visited.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a - 1].push_back(b - 1);
        adj[b - 1].push_back(a - 1);
    }

    int graphs = 0;
    vector<int> not_visited;
    for (int i = 0; i < n; i++) {
        if (!is_visited[i]) {
            graphs++;
            not_visited.push_back(i);
            dfs(i);
        }
    }

    cout << graphs - 1 << "\n";
    for (int i = 0; i < not_visited.size() - 1; i++) {
        cout << not_visited[i] + 1 << " " << not_visited[i + 1] + 1 << "\n";
    }
}