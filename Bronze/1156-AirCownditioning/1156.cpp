#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int p[n];
    int t[n];
    int d[n];
    int state = 0;
    int total = 0;
    int empty = 1;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> t[j];
    }

    for (int k = 0; k < n; k++) {
        d[k] = p[k] - t[k];
    }
    
    while (empty == 1) {
        for (int l = 0; l < n; l++) {
            if (d[l] > 0) {
                if (state == 0) {
                    total++;
                    state = 1;
                    d[l] = d[l] - 1;
                } else {
                    d[l] = d[l] - 1;
                }
            } else {
                state = 0;
            }
        }
        for (int i = 0; i < n; i++) {
            if (d[i] != 0) {
                empty = 1;
                break;
            } else {
                empty = 0;
            }
        }
    }

    cout << total << "\n";
}
