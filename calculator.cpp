#include <iostream>

int main() {
  char op;
  double num1;
  double num2;

  while (true) {
    std::cout << "Enter the operator you wish to choose: ";
    std::cin >> op;

    std::cout << "Enter the first number: ";
    std::cin >> num1;
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    switch (op) {
    case '+':
      std::cout << num1 + num2;
      break;
    case '-':
      std::cout << num1 - num2;
      break;
    case '*':
      std::cout << num1 * num2;
      break;
    case '/':
      std::cout << num1 / num2;
      break;
    default:
      std::cout << "Please enter a valid operator (+, -, *, /)" << '\n';
      continue;
    }
    break;
  }
}
