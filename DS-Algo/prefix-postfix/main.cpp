#include <iostream>
#include "StacksQueues/StacksQueues.hpp"

bool isOperator(char x) {
  switch (x) {
  case '+':
  case '-':
  case '/':
  case '*':
    return true;
  }
  return false;
}

std::string prefixToPostfix(std::string preFixExp) {

    Stack<std::string> s;

    int length = preFixExp.size();

    for (int i = length - 1; i >= 0; i--) {
 
        if (isOperator(preFixExp[i])) {
            std::string op1 = s.popAndReturnData();
            std::string op2 = s.popAndReturnData();
            std::string temp = op1 + op2 + preFixExp[i];
            s.push(temp);
        } else {
            s.push(std::string(1, preFixExp[i]));
        }
    }

    return s.returnTop();
}

int main() {

    std::string preFixExp = "*-A/BC-/AKL";
    std::cout << "Prefix : " << preFixExp << "\n";
    std::cout << "Postfix : " << prefixToPostfix(preFixExp) << "\n";

    return 0;
}