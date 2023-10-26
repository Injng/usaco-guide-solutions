#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, a, q;
        cin >> n >> a >> q;
        string notifications;
        cin >> notifications;
        int count = a;
        for (int i = 0; i < q; i++) {
            if (a == n) {
                cout << "YES\n";
                break;
            }

            if (notifications[i] == '+') {
                a++;
                count++;
            } else a--;

            if (a == n) {
                cout << "YES\n";
                break;
            } else if (i == q - 1 && count >= n) cout << "MAYBE\n";
            else if (i == q - 1) cout << "NO\n";
        }
    }
}