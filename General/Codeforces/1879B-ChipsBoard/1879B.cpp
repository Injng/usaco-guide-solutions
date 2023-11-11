#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a, b;
        long long row_sum = 0, col_sum = 0;
        for (int i = 0; i < n; i++) {
            long long in;
            cin >> in;
            a.push_back(in);
            row_sum += in;
        }
        for (int i = 0; i < n; i++) {
            long long in;
            cin >> in;
            b.push_back(in);
            col_sum += in;
        }

        long long a_min = *min_element(a.begin(), a.end());
        long long b_min = *min_element(b.begin(), b.end());
        if (a_min * n + col_sum < b_min * n + row_sum) {
            cout << *min_element(a.begin(), a.end()) * n + col_sum << "\n";
        } else {
            cout << *min_element(b.begin(), b.end()) * n + row_sum << "\n";
        }
    }
}