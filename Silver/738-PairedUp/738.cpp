#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);

    int n;
    cin >> n;
    vector<pair<int, int>> cows;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cows.emplace_back(b, a);
    }

    sort(cows.begin(), cows.end());

    int time = 0;
    int left = 0, right = n - 1;
    while (left <= right) {
        int sum = cows[left].first + cows[right].first;
        time = time < sum ? sum : time;
        if (left == right) break;
        if (cows[left].second > cows[right].second) {
            cows[left].second -= cows[right--].second;
        } else if (cows[left].second < cows[right].second) {
            cows[right].second -= cows[left++].second;
        } else {
            left++;
            right--;
        }
    }

    cout << time << "\n";
}