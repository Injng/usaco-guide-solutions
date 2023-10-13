#include <bits/stdc++.h>

using namespace std;


int main() {

    freopen("int", "r", stdin);

    freopen("diamond.out", "w", stdout);



    int n, k; cin >> n >> k;



    //Make sorted vector of diamond sizes.

    vector<int> diamonds(n);

    for (int &diamond : diamonds) {

        cin >> diamond;

    }

    sort(diamonds.begin(), diamonds.end());





    //max number of diamonds in case when i is the smallest diamond

    vector<int> amountsAboveI(n);



    //max number of diamonds in case when i is the largest diamond

    vector<int> amountsBelowI(n);



    //Use 2 pointer method to fill in these vectors

    int i1 = 0;

    int i2 = 0;

    while (i2 < n) {

        if (diamonds[i2] - diamonds[i1] <= k) {

            amountsAboveI[i1] = i2 - i1 + 1;

            amountsBelowI[i2] = i2 - i1 + 1;

            i2++;

        } else i1++;

    }





    //Find max possible amount of diamonds in 2 cases.

    int ans = 0;

    int maxAmountBelow = 0;



    for (int i=1; i<n; i++) {

        maxAmountBelow = max(maxAmountBelow, amountsBelowI[i-1]);

        ans = max(ans, amountsAboveI[i] + maxAmountBelow);

    }



    cout << ans;

    return 0;

}