#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  int num;
  int guess;

  srand(time(0));

  num = rand() % 100 + 1;

  std::cout << "***********Number Game***********" << std::endl;

  do {
    std::cout << "Enter your guess: ";
    std::cin >> guess;
    if (guess == num) {
      break;
    }
    if (guess > num) {
      std::cout << "Smaller" << std::endl;
    } else {
      std::cout << "Greater" << std::endl;
    }
  } while (guess != num);

  std::cout << "Congratulations!! You guessed the number correctly!" << '\n';
  std::cout << "*********************************" << std::endl;
}
