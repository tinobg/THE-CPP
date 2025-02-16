#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

class RPN {
public:
    static int evaluate(const std::string& expression);
private:
    static bool isOperator(char c);
    static int applyOperation(char op, int a, int b);
};

#endif
