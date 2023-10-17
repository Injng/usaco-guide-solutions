#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        vector<long long> vec;
        long long sum = 0;
        for (long long i = 0; i < n; i++) {
            long long x;
            cin >> x;
            sum += x;
            vec.push_back(x);
        }

        vec.push_back(n * (n + 1) / 2 - sum);
        for (long long i = n + 1 - k % (n + 1); i < n + 1 - k % (n + 1) + n; i++) {
            cout << vec[i % (n + 1)] << " ";
        }
        cout << "\n";
    }
}