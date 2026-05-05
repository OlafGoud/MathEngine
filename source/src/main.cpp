
#include <iostream>
#include <string>

#include "tokenizer.h"

int main() {
  std::cout << "enter input: ";
  std::string str;
  std::getline(std::cin >> std::ws, str);
  tokenize(str);

  return 0;
}
