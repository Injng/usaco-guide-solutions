#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string cows;
    string test;
    int g; 
    int h; 
    int total = 0;
    cin >> cows;
    int cowlength = cows.length();

    for (int a = 3; a <= cowlength; a++) {
        for (int b = 0; b <= (cowlength - a); b++) {
            test = cows.substr(b, a);
            g = count(test.begin(), test.end(), 'G');
            h = count(test.begin(), test.end(), 'H');
            if (g == 1 || h == 1) {
                total++;
            }
        }
    }

    cout << total << "\n";
}
    

