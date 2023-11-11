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
        int n, k;
        cin >> n >> k;
        int problems[n];
        for (int i = 0; i < n; i++) {
            cin >> problems[i];
        }

        sort(problems, problems + n);
        int start = 0;
        vector<int> diff;
        for (int i = 0; i < n; i++) {
            if (n == 1) {
                diff.push_back(1);
            } else if (problems[i] - problems[i - 1] > k) {
                diff.push_back(i - start);
                start = i;
            } else if (i == n - 1) {
                diff.push_back(i - start + 1);
            } else if (i == 0) {
                start = 0;
            }
        }

        cout << n - *max_element(diff.begin(), diff.end()) << "\n";
    }
}