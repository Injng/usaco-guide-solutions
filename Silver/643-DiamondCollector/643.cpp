#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> diamonds;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        diamonds.push_back(a);
    }

    sort(diamonds.begin(), diamonds.end());

    vector<int> before(n);
    vector<int> after(n + 1);
    int left = 0, right = 0;
    while (left < n && right < n) {
        while (diamonds[right] - diamonds[left] <= k) {
            before[right] = right - left + 1;
            after[left] = right - left + 1;
            right++;
            if (right == n) break;
        }
        left++;
    }

    int ans = 0, max_first = 0;
    for (int i = 0; i < n; i++) {
        max_first = max(max_first, before[i]);
        ans = max(ans, max_first + after[i + 1]);
    }

    cout << ans << "\n";
}