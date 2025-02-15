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
    static bool isOperator(const std::string& token);
    static int applyOperation(const std::string& op, int a, int b);
};

#endif
