#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  freopen("rental.in", "r", stdin);
  freopen("rental.out", "w", stdout);
  
  int n, m, r;
  cin >> n >> m >> r;
  vector<int> cows;
  vector<pair<int, int>> stores;
  vector<int> farms;
  
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    cows.push_back(a);
  }

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> b >> a;
    stores.push_back(make_pair(a, b));
  }

  for (int i = 0; i < r; i++) {
    int in;
    cin >> in;
    farms.push_back(in);
  }

  sort(cows.begin(), cows.end(), greater<int>());
  sort(stores.begin(), stores.end(), greater<pair<int, int>>());
  sort(farms.begin(), farms.end(), greater<int>());

  int store_index = 0;
  int farm_index = 0;
  int cow_index = 0;
  long long total = 0;

  while (cow_index < n) {
    int milk = cows[cow_index];
    int milk_left = milk;
    int curr_store = store_index;
    int curr_farm = farm_index;
    int amt_left;
    int sell_price = 0;
    int rent_price = 0;

    while (curr_store < m) {
      int sold = min(milk_left, stores[curr_store].second);
      milk_left -= sold;
      if (milk_left == 0) {
        sell_price += sold * stores[curr_store].first;
        amt_left = sold;
        break;
      } else {
        sell_price += sold * stores[curr_store].first;
        curr_store++;
      }  
    }

    rent_price += farm_index < m ? farms[farm_index] : -1;

    if (sell_price >= rent_price) {
      total += sell_price;
      store_index = curr_store;
      if (store_index < m) stores[store_index].second -= amt_left;
      cow_index++;
    } else {
      n--;
      farm_index++;
      total += rent_price;
    }
  }

  cout << total << "\n";
}
