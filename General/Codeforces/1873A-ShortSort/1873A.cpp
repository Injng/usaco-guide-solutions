#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string abc;
        cin >> abc;
        if (abc == "bca" || abc == "cab") {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}