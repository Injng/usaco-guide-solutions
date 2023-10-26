#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int evens = 0;
    int odds = 0;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if (a % 2 == 0) evens++;
        else odds++;
    }

    while (odds > evens) {
        odds -= 2;
        evens++;
    }
    if (evens > odds + 1) evens = odds + 1;
    cout << evens + odds << "\n";
}