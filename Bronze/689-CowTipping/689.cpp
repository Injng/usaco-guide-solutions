#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);

    int N;
    cin >> N;
    int grid[N][N];

    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            if (row[j] == '0') grid[i][j] = 0;
            else grid[i][j] = 1;
        }
    }

    int count = 0;
    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            if (grid[i][j] == 1) {
                count++;
                for (int k = 0; k <= i; k++) {
                    for (int l = 0; l <= j; l++) {
                        grid[k][l] = 1 - grid[k][l];
                    }
                }
            }
        }
    }

    cout << count << "\n";
}