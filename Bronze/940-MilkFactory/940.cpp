#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> belts(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        belts[a] = b;
    }

    int station_i = -1;
    for (int i = 1; i <= n; i++) {
        if (belts[i] == 0) {
            if (station_i == -1) {
                station_i = i;
            } else {
                cout << -1 << "\n";
                return 0;
            }
        }
    }

    cout << station_i << "\n";
}