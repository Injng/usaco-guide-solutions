#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string x;
        cin >> x;
        int round = x.size();
        for (int i = x.size() - 1; i > 0; i--) {
            if (x[i] - '0' >= 5) {
                x[i - 1] = x[i - 1] != '9' ? x[i - 1] + 1 : x[i - 1];
                round = i;
            }
        }
        if (x[0] - '0' >= 5) {
            round = 0;
            cout << "1";
        }
        for (int i = 0; i < x.size(); i++) {
            if (i >= round) cout << "0";
            else cout << x[i];
        }
        cout << "\n";
    }
}