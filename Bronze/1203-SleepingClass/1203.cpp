#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  int n;
  int value;
  int same;
  int sum = 0;
  vector<int> sleeping;
  cin >> t;

  for (int a = 0; a < t; a++) {
    cin >> n;
    
    for (int b = 0; b < n; b++) {
      cin >> value;
      sum = sum + value;
      sleeping.push_back(value);
    }

    for (int i = 1; i <= sum; i++) {
      if (sum % i != 0) {
	continue;
      }

      same = sum / i;

      // Not completed, skipped

      
    
