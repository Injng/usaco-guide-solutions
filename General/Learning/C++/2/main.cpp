#include "ops.h"
#include <iostream>

using std::cin;
using std::cout;

int main()
{
  int a;
  cout << "Enter first integer: ";
  cin >> a;

  int b;
  cout << "Enter second integer: ";
  cin >> b;

  cout << "Sum: " << add(a, b) << "\n";
  cout << "Difference: " << subtract(a, b) << "\n";
  cout << "Product: " << multiply(a, b) << "\n";
  cout << "Quotient: " << divide(a, b) << "\n";

  return 0;
}
