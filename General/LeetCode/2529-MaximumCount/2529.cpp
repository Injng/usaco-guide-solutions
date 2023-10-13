#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> nums = {5, 20, 66, 1314};
  int l = 0;
  int r = 0;
  int n = nums.size();
  int stopL = 0;
  int stopR = 0;

  for (int i = n / 2; i > 0; i /= 2) {
    if (stopL == 0) {
      while (l + i < n && nums[l + i] < 0) {
	l += i;
      }

      if (l == n - 1) {
	if (nums[l] < 0) {
	  l = n;
	  stopL = 1;
	}
      } else if (nums[l + 1] >= 0) {
	stopL = 1;
      }
    }

    if (stopR == 0) {
      while (r + i < n && nums[r + i] <= 0) {
	r += i;
      }

      if (r == 0) {
	if (nums[r] > 0) {
	  r = -1;
	  stopR = 1;
	}
      } else if (nums[r - 1] <= 0) {
	stopR = 1;
      }
    }

    if (stopL == 1 && stopR == 1) break;
  }

  int neg = l + 1;
  int pos = n - (r + 1);

  if (neg > pos) {
    cout << neg;
  } else {
    cout << pos;
  }
  cout << "\n";
}
