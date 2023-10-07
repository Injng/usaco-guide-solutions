#include <bits/stdc++.h>

using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1]));
    int n = rand(5, 10);
    int k = rand(2, 10);
    cout << n << " " << k << "\n";
    for (int i = 0; i < n; i++) {
        cout << rand(1, 20) << "\n";
    }
}