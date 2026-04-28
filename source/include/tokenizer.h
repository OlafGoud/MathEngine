#include <iostream>
#include <string.h>
#include <vector>
#include <unordered_map>

void tokenize(std::string userInputString);
std::vector<std::string> stringToTokens(const std::string &userInputString);

bool isNumber(const std::string &str);
bool isNumber(const char c);
bool isCharacter(const char c);
bool isIrrationalNumber(const std::string &str);
bool isOperator(const std::string &token, std::vector<std::string> operatorList, int checkLimit);
bool isOperator(const std::string &token, std::vector<std::string> operatorList);
bool isRightAssociative(const std::string &str); // map

double getNumber(const std::string &str);
int getOperatorPriority(const std::string &str); // map

bool validateToken(std::string &token, std::vector<std::string> operatorList);