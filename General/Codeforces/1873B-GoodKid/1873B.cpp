#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            int in;
            cin >> in;
            arr[i] = in;
        }

        int increase_min = *min_element(arr, arr + n);
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == increase_min) {
                ans *= arr[i] + 1;
                increase_min = -1;
            } else {
                ans *= arr[i];
            }
        }

        cout << ans << "\n";
    }
}