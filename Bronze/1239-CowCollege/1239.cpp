#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int n;
    cin >> n;
    long long int tuition[n];
    long long int profit[n];

    for (int i = 0; i < n; i++) {
        cin >> tuition[i];
    }

    sort(tuition, tuition + n);

    for (int j = 0; j < n; j++) {
        profit[j] = tuition[j] * (n - j);
    }
    
    long long int index = distance(profit, max_element(profit, profit + n));
    long long int optimal = tuition[index];

    cout << *max_element(profit, profit + n) << " " << optimal << "\n";
}



