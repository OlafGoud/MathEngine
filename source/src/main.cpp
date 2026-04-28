
#include <iostream>
#include <cmath>
#include <string>

#include "tokenizer.h"

int main() {
  std::cout << std::log(10) << '\n';
  std::cout << std::log(1) << '\n';
  std::cout << std::log10(10) << '\n';
  std::cout << std::log10(100) << '\n';
  std::string str;
  std::getline(std::cin >> std::ws, str);

  stringToTokens(str);

  return 0;
}