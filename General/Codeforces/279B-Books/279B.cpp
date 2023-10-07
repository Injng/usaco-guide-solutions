#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;
    int read_times[n];
    for (int i = 0; i < n; i++) {
        cin >> read_times[i];
    }

    int left = 0, right = 0;
    int books_read = 0;
    int sum = 0;

    while (left < n && right < n) {
        while (right < n) {
            sum += read_times[right++];
            if (sum > t) {
                sum -= read_times[--right];
                break;
            }
        }

        int read_count = right - left;
        books_read = max(books_read, read_count);
        sum -= read_times[left++];
    }

    cout << books_read << "\n";
}