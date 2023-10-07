#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        char prev = s[0];
        int block = 0;
        int ans = 0;
        vector<int> block_vec;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] == prev) {
                block++;
            } else {
                if (block != 0) {
                    block_vec.push_back(block + 1);
                    ans += block;
                }
                block = 0;
            }
            prev = s[i];
        }
        if (block != 0) {
            block_vec.push_back(block + 1);
            ans += block;
        }

        cout << ans << " ";

        ans = 1;
        for (int b : block_vec) {
            ans %= 998244353;
            ans *= tgamma(b + 1);
        }
        ans *= tgamma(block_vec.size() + 1);

        cout << ans << "\n";
    }
}