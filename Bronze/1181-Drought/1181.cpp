#include <iostream>
#include <vector>
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
        vector<long long> cows;
        for (int i = 0; i < n; i++) {
            long long h;
            cin >> h;
            cows.push_back(h);
        }

        if (n == 1) {
            cout << -1 << "\n";
            continue;
        }

        int state = 0;
        long long ans = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (cows[j] > cows[j - 1]) {
                    ans += 2 * (cows[j] - cows[j - 1]);
                    cows[j + 1] -= cows[j] - cows[j - 1];
                    cows[j] -= cows[j] - cows[j - 1];
                }
            }

            if (cows[n - 1] > cows[n - 2]) {
                state = -1;
                break;
            }

            reverse(cows.begin(), cows.end());
        }

        if (state == -1 || cows[0] < 0) {
            cout << -1 << "\n";
        } else {
            cout << ans << "\n";
        }
    }
}