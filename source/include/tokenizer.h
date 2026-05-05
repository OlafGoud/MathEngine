#include <iostream>
#include <string.h>
#include <vector>
#include <set>

void tokenize(std::string userInputString);
std::vector<std::string> stringToTokens(const std::string &userInputString);
void cleanEquation(std::vector<std::string> &tokenList);


bool isNumber(const std::string &str);
bool isNumber(const char c);
bool isCharacter(const char c);
double getNumber(const std::string &str);

bool validateToken(const std::string &token, std::vector<std::string> &tokenList, const std::set<std::string> &operatorSet);

