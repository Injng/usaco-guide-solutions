#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    int values[n];
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    int left = 0, right = n - 1;
    while (left < right) {
        if (values[left] + values[right] == x) {
            cout << left + 1 << " " << right + 1 << "\n";
            return 0;
        } else if (values[left] + values[right] < x) {
            left++;
        } else {
            right--;
        }
    }

    cout << "IMPOSSIBLE\n";
}