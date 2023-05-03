#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<char> > finalPatches;
vector<int> numPatches;

vector<char> elementReplace(int i, char r, vector<char> original) {
    original[i] = r;
    return original;
}

void nextPatch(int k, int n, int x, vector<char> &cows, vector<char> &patches) {
    if (x == n) {
        finalPatches.push_back(patches);
        int countG = count(patches.begin(), patches.end(), 'G');
        int countH = count(patches.begin(), patches.end(), 'H');
        int count = countG + countH;
        numPatches.push_back(count);
    }

    vector<char> newPatches;

    if (cows[x] == 'G') {
        for (int i = x - k; i <= x + k; i++) {
            if (patches[i] == 'G') {
                nextPatch(k, n, x + 1, cows, patches);
                break;
            } else if (patches[i] == '.') {
                newPatches = elementReplace(i, 'G', patches);
                nextPatch(k, n, x + 1, cows, newPatches);
                newPatches.clear();
            }
        }
    } else {
        for (int j = x - k; j <= x + k; j++) {
            if (patches[j] == 'H') {
                nextPatch(k, n, x + 1, cows, patches);
                break;
            } else if (patches[j] == '.') {
                newPatches = elementReplace(j, 'H', patches);
                nextPatch(k, n, x + 1, cows, newPatches);
                newPatches.clear();
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    vector<char> patches;
    vector<char> cows;
    vector<string> strans;
    vector<int> intans;
    cin >> t;

    for (int a = 0; a < t; a++) {
        int n;
        int k;
        string cow;
        cin >> n >> k;
        cin >> cow;
        copy(cow.begin(), cow.end(), back_inserter(cows));
        for (int b = 0; b < n; b++) {
            patches.push_back('.');
        }
        nextPatch(k, n, 0, cows, patches);
        int minPatches = *min_element(numPatches.begin(), numPatches.end());
        int index = distance(numPatches.begin(), min_element(numPatches.begin(), numPatches.end()));
        string patch(finalPatches[index].begin(), finalPatches[index].end());
        strans.push_back(patch);
        intans.push_back(minPatches);
        cows.clear();
        patches.clear();
        finalPatches.clear();
        numPatches.clear();
    }

    for (int c = 0; c < t; c++) {
        cout << intans[c] << "\n";
        cout << strans[c] << "\n";
    }
} 

