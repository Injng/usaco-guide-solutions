#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        string paper;
        cin >> paper;

        int count = 0;
        int cell = 0;
        while (cell < n) {
            if (paper[cell] == 'B') {
                count++;
                cell += k;
            } else {
                cell++;
            }
        }

        cout << count << "\n";
    }
}