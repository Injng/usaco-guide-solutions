#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int m, n, k;
    cin >> m >> n >> k;
    char signal[m][n];

    for (int i = 0; i < m; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++) {
            signal[i][j] = row[j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int a = 0; a < k; a++) {
            for (int j = 0; j < n; j++) {
                for (int b = 0; b < k; b++) {
                    cout << signal[i][j];
                }
            }
            cout << "\n";
        }
    }
}