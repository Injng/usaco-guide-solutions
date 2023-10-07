#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);

    int n;
    cin >> n;
    int cows[n];
    for (int i = 0; i < n; i++) cin >> cows[i];

    for (int i = n - 2; i >= 0; i--) {
        if (cows[i] > cows[i + 1]) {
            cout << i + 1 << "\n";
            return 0;
        }
    }

    cout << 0 << "\n";
}