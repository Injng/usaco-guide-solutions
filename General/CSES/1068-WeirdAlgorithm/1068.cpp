#include <cstdio>
using namespace std;

int main()
{
  long long x;
  scanf("%lld", &x);
  printf("%lld ", x);

  while (x != 1) {
    if (x % 2 != 0) {
      x = 3 * x + 1;
      printf("%lld ", x);
    } else {
      x = x / 2;
      printf("%lld ", x);
    }
  }

  return 0;
}

