#include "tokenizer.h"
#include <functional>
#include <unordered_map>


struct mathOperator {
  std::function<double(double, double)> operatorFunction;
  unsigned int inputSize;
  unsigned int operatorPriority;
  int needOperator;
  bool rightAssociative;
};

std::unordered_map<std::string, mathOperator> operatorMap;
std::set<std::string> irregularNumbers;


void tokenize(std::string userInputString) {

  operatorMap["pi"] = {[](float a, float b) {return 3.14159265359;}, 0, 5, 6, false};
  operatorMap["e"] = {[](float a, float b) {return 3.14159265359;}, 0, 5, 6, false};  
  irregularNumbers.insert("e");
  irregularNumbers.insert("pi");

  operatorMap["+"] = {[](float a, float b) {return a + b;}, 2, 1, 0, false}; 
  operatorMap["-"] = {[](float a, float b) {return a - b;}, 2, 1, 0, false}; 

  operatorMap["*"] = {[](float a, float b) {return a * b;}, 2, 2, 0, false}; 
  operatorMap["/"] = {[](float a, float b) {return a / b;}, 2, 2, 0, false}; 


  std::vector<std::string> tokenList = stringToTokens(userInputString);
  if(tokenList.empty()) return;
  cleanEquation(tokenList);

  std::cout << "-----------------\n";
  for(std::string str : tokenList) {
    std::cout << "token: " << str << "\n";
  }
  

}

void cleanEquation(std::vector<std::string> &tokenList) {
  if(tokenList[0] == "-") {
    tokenList.insert(tokenList.begin(), "0");
  }


  for(int i = 0; i < tokenList.size(); i++) { 
    if(!(operatorMap[tokenList[i]].needOperator > 0 || tokenList[i] == ")" || tokenList[i] == "(")) continue;


    /** back operator pass */
    if(i < tokenList.size() - 1 && operatorMap[tokenList[i]].needOperator % 3 == 0)
      if (isNumber(tokenList[i + 1]) || irregularNumbers.contains(tokenList[i + 1]))
        tokenList.insert(tokenList.begin() + (i + 1), "*");
 
    /** front operator pass */
    if(i > 0 && operatorMap[tokenList[i]].needOperator % 2 == 0) 
      if(isNumber(tokenList[i - 1]) || irregularNumbers.contains(tokenList[i - 1]))
        tokenList.insert(tokenList.begin() + i, "*");
  }
}

std::vector<std::string> stringToTokens(const std::string &userInputString) {
  std::vector<std::string> tokenList{};

  std::set<std::string> operatorSet{};

  for(auto [key, val] : operatorMap) {
    operatorSet.insert(key);
  } 
  


  int idx = 0;
  while (idx < userInputString.size()) {
    std::string token{};

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

      if(validateToken(token, tokenList, operatorSet)) {
        std::cout << "MATH_ERR\n";
      }
      continue; /** already added in validateToken if there was a token */
    } else {
      std::cout << "not a valid token: " << token << ". IGNORED\n";
      idx++;
    }

    tokenList.push_back(token);
  }

  return tokenList;
}


/** Vallidates if a token is a operator or a other function. 
 * returns true(1) if an error occured!
 */
bool validateToken(const std::string &token, std::vector<std::string> &tokenList, const std::set<std::string> &operatorSet) {

  if(operatorSet.contains(token)) {
    tokenList.push_back(token);
    return false;
  }
  int wordIndex = 0;
  for(int i = token.size(); i >= wordIndex; i--) {
    std::string temp;
    for (int n = wordIndex; n < i; n++) {
      temp += token[n];
    }

    if(operatorSet.contains(temp)) {
      tokenList.push_back(temp);
      wordIndex = i;
      i = token.size() + 1;
    } 
  }
  if (wordIndex < token.size()) return true;

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
  return (c >= '!' && c <= '~') && !isNumber(c);
}


double getNumber(const std::string &str) {return 0;};
