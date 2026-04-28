#include "tokenizer.h"
#include <functional>
#include <vector>


struct mathOperator {
  std::function<double(double, double)> operatorFunction;
  unsigned int inputSize;
  
};

std::unordered_map<std::string, mathOperator> operatorMap;


void tokenize(std::string userInputString) {


}



std::vector<std::string> stringToTokens(const std::string &userInputString) {
  std::vector<std::string> tokenList{};

  std::vector<std::string> operatorNameList{};
  operatorNameList.push_back("plus");
  operatorNameList.push_back("+");
  for(auto [key, val] : operatorMap) {
    operatorNameList.push_back(key);
  } 
  int idx = 0;
  while (idx < userInputString.size()) {
    std::string token{};
  std::cout << "new\n";

    if(userInputString[idx] == ' ') {
      idx++; 
      continue;
    }

    if(isNumber(userInputString[idx])) {
      while (isNumber(userInputString[idx])) {
        token += userInputString[idx++];
      }
    } 
    else if (isCharacter(userInputString[idx])) {
      while (isCharacter(userInputString[idx])) {
        token += userInputString[idx++];
      }

      if(validateToken(token, operatorNameList)) {

      }


    }





    tokenList.push_back(token);
  }

  return tokenList;
}

void evaluteTokens() {

}


bool validateToken(std::string &token, std::vector<std::string> operatorList) {

  if(isOperator(token, operatorList)) return true;

  for(int i = token.size() - 1; i >= 0; i--) {
    if(isOperator(token, operatorList, i)) {
      std::cout << token << ", " << i << "\n";
    }

  }

  return false;
}

bool isNumber(const std::string &str) {
  bool valid = true;
  if(str.length() < 1) return false;
  for(char c : str) {
    if (!((c >= '0' && c <= '9') || c == '.')) valid = false;
  }
  return valid;
}

bool isNumber(const char c) {
  return (c >= '0' && c <= '9') || c == '.';
}

bool isCharacter(const char c) {
  return (c >= '!' && c <= '~');
}

bool isIrrationalNumber(const std::string &str) {return false;}

bool isOperator(const std::string &token, std::vector<std::string> operatorList) {

  for(std::string &str : operatorList) {
    if(str == token) return true;
  }

  return false;
}

bool isOperator(const std::string &token, std::vector<std::string> operatorList, int checkLimit) {

  std::string temp;
  for(int i = 0; i < token.size() && i < checkLimit; i++) {
    temp += token[i];
  }

  for(std::string &str : operatorList) {
    if(str == temp) {
      std::cout << temp << "\n"; 
      return true;
    }
  }

  return false;


} 


bool isRightAssociative(const std::string &str) {return false;} // map

double getNumber(const std::string &str) {};
int getOperatorPriority(const std::string &str) {return 1;} // map
