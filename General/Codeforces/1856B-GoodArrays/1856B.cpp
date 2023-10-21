#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long sum = 0;
        int one_count = 0;
        for (int i = 0; i < n; i++) {
            long long a;
            cin >> a;
            sum += a;
            if (a == 1) one_count++;
        }

        if (n == 1) cout << "NO\n";
        else if (sum >= n + one_count) cout << "YES\n";
        else cout << "NO\n";
    }
}