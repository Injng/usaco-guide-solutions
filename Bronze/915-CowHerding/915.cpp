#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    int cows[3];
    cin >> cows[0] >> cows[1] >> cows[2];

    sort(cows, cows+3);

    int first = cows[1] - cows[0];
    int second = cows[2] - cows[1];
    int min_interval = min(first, second);

    if (min_interval == 2) cout << 1 << "\n";
    else if (first == 1 && second == 1) cout << 0 << "\n";
    else cout << 2 << "\n";

    cout << max(first, second) - 1 << "\n";
}