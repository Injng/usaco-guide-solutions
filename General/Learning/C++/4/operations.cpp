#include <iostream>

double calculations(double x, double y, char oper) {
  if (oper == '+')
    return x + y;
  else if (oper == '-')
    return x - y;
  else if (oper == '*')
    return x * y;
  else if (oper == '/')
    return x / y;
  return 0;
}

int main() {
  double value1;
  std::cout << "Enter a double value: ";
  std::cin >> value1;

  double value2;
  std::cout << "Enter a double value: ";
  std::cin >> value2;

  char operation;
  std::cout << "Enter one of the following: +, -, *, or /: ";
  std::cin >> operation;

  double finalvalue = calculations(value1, value2, operation);
  std::cout << value1 << " " << operation << " is " << finalvalue;

  return 0;
} 
  
