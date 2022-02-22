#include <iostream>

int main() {
  char input;
  std::cout << "Enter a single character: ";
  std::cin >> input;
  std::cout << "\n \n";

  std::cout << "Your character is: " << input << "\n";
  std::cout << "Corresponding ASCII code is: " << static_cast<int>(input) << "\n";
}

