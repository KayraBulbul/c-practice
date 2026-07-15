#include <iostream>

int main() {
  char unit;
  double temperature;

  std::cout << "What unit do you want to convert to (F, C): ";
  std::cin >> unit;

  std::cout << "Enter temperature value: ";
  std::cin >> temperature;

  if (unit == 'C') {
    double tempInCelsius = (temperature - 32) / 1.8;
    std::cout << temperature << "F is equal to " << tempInCelsius << "C."
              << std::endl;
  } else {
    double tempInFahrenheit = temperature * 1.8 + 32;
    std::cout << temperature << "C is equal to " << tempInFahrenheit << "F."
              << std::endl;
  }
  return 0;
}
