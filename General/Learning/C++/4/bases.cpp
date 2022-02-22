#include <iostream>
#include <bitset>

int main() {
  int number;
  std::cout << "Enter an integer: ";
  std::cin >> number;
  std::cout << "\n \n";

  std::cout << "Decimal: " << number << "\n";
  std::cout << "Hexadecimal: ";
  std::cout << std::hex << number << "\n";
  std::cout << "Octal: ";
  std::cout << std::oct << number << "\n";
  std::cout << "Binary: ";
  std::bitset<32> bin1 = number;
  std::cout << bin1 << "\n";
}
