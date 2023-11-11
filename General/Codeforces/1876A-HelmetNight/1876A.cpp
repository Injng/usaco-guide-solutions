#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, p;
        cin >> n >> p;
        long long a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        pair<long long, long long> b[n];
        for (int i = 0; i < n; i++) {
            long long in;
            cin >> in;
            b[i] = make_pair(a[i], in);
        }

        sort(b, b + n, [] (pair<long long, long long> a, pair<long long, long long> b) {
            if (a.second == b.second) return a.first > b.first;
            else return a.second < b.second;
        });

        long long ans = 0;
        long long l = 0;
        long long r = n - 1;
        while (l <= r) {
            if (b[l].second >= p) {
                if (l == 0) ans += p * (r - l);
                else ans += p * (r - l + 1);
                break;
            }

            long long total_spread;
            if (l == 0) total_spread = b[l].first < r - l ? b[l].first : r - l;
            else total_spread = b[l].first - 1 < r - l ? b[l].first : r - l + 1;

            ans += total_spread * b[l].second;
            if (l == 0) r -= total_spread;
            else r -= total_spread - 1;
            l++;
        }

        ans += p;
        cout << ans << "\n";
    }
}