#include <iostream>
#include <string>
#include <vector>

using namespace std;

int analyse(int n, int x, vector<int> set, vector<vector<int> > ainputs, vector<int> outputs) {
    if (x == n) {
        return 0;
    }

    vector<int> inputs = ainputs[x];
    int output = outputs[x];
    int test = 0;

    if (output == 0) {
        for (int i = 0; i < n; i++) {
            if (set[i] == 0) {
                break;
            } else if (set[i] == 2) {
                set[i] = 0;
                int det = analyse(n, x + 1, set, ainputs, outputs);
                if (det == 1) {
                    return 1;
                } else {
                    return 0;
                }
                set[i] = 2;
                test = 1;
            } else {
                return 1;
            }
        }
    } else {
        for (int j = 0; j < n; j++) {
            if (set[j] == 1) {
                break;
            } else if (set[j] == 2) {
                set[j] = 1;
                int det = analyse(n, x + 1, set, ainputs, outputs);
                if (det == 1) {
                    return 1;
                } else {
                    return 0;
                }
                set[j] = 2;
                test = 1;
            } else {
                return 1;
            }
        }
    }

    if (test == 0) {
        return 1;
    }
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    for (int a = 0; a < t; a++) {
        int n;
        int m;
        cin >> n >> m;
        vector<vector<int> > ainputs;
        vector<int> outputs;
        vector<int> set;
        for (int b = 0; b < m; b++) {
            vector<int> inputs;
            string input;
            cin >> input;
            for (int c = 0; c < n; c++) {
                inputs.push_back(stoi(input.substr(c, 1)));
            }
            ainputs.push_back(inputs);
            inputs.clear();
            int output;
            cin >> output;
            outputs.push_back(output);
        }
        for (int d = 0; d < m; d++) {
            set.push_back(2);
        }
        int result = analyse(n, 0, set, ainputs, outputs);
        if (result == 0) {
            cout << "OK\n";
        } else {
            cout << "LIE\n";
        }
    }
}
