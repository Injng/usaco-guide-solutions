#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        char target[10][10];
        for (int i = 0; i < 10; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < 10; j++) {
                target[i][j] = s[j];
            }
        }

        int count = 0;
        for (int i = 1; i <= 5; i++) {
            for (int j = i - 1; j <= 10 - i; j++) {
                if (target[i - 1][j] == 'X') count += i;
            }
            for (int j = i; j <= 10 - i; j++) {
                if (target[j][10 - i] == 'X') count += i;
            }
            for (int j = i - 1; j < 10 - i; j++) {
                if (target[10 - i][j] == 'X') count += i;
            }
            for (int j = i; j < 10 - i; j++) {
                if (target[j][i - 1] == 'X') count += i;
            }
        }

        cout << count << "\n";
    }
}