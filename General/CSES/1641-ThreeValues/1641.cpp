#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> val;
    for (int i = 0; i < n; i++) {
        int in;
        cin >> in;
        val.emplace_back(in, i);
    }

    sort(val.begin(), val.end());

    for (int third = 0; third < n; third++) {
        int left = 0;
        int right = n - 1;
        while (left < right) {
            if (left != third && right != third) {
                int sum = val[left].first + val[right].first + val[third].first;
                if (sum == x) {
                    cout << val[left].second + 1 << " " << val[right].second + 1 << " " << val[third].second + 1 << "\n";
                    return 0;
                } else if (sum > x) {
                    right--;
                } else {
                    left++;
                }
            } else if (left == third) {
                left++;
            } else {
                right--;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
}