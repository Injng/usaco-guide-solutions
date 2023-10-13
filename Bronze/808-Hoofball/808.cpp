#include <iostream>
#include <algorithm>

using namespace std;

int N, cows[100], passed_to[100];

int pass_to(int i) {
    if (i == 0) {
        return i + 1;
    } else if (i == N - 1) {
        return i - 1;
    } else if (cows[i + 1] - cows[i] < cows[i] - cows[i - 1] ) {
        return i + 1;
    } else {
        return i - 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> cows[i];

    sort(cows, cows + N);

    for (int i = 0; i < N; i++) {
        passed_to[pass_to(i)]++;
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (passed_to[i] == 0) {
            count++;
        } else if (i < pass_to(i) && pass_to(pass_to(i)) == i && passed_to[i] == 1 && passed_to[pass_to(i)] == 1) {
            count++;
        }
    }

    cout << count << "\n";
}