#include "RPN.hpp"

bool RPN::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::applyOperation(char op, int a, int b) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') {
        if (b == 0) throw std::runtime_error("Error: Division by zero");
        return a / b;
    }
    throw std::runtime_error("Error: Invalid operator");
}

int RPN::evaluate(const std::string& expression) {
    if (expression.empty()) throw std::runtime_error("Error: Empty expression");

    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;
    int countNumbers = 0, countOperators = 0;

    while (iss >> token) {
        if (token.find_first_not_of("0123456789+-*/ ") != std::string::npos) {
            throw std::runtime_error("Error: Invalid character");
        }

        if (token.size() == 1 && std::isdigit(token[0])) {
            stack.push(token[0] - '0');
            countNumbers++;
        } else if (token.size() == 1 && isOperator(token[0])) {
            if (stack.size() < 2) throw std::runtime_error("Error: Malformed expression");
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            stack.push(applyOperation(token[0], a, b));
            countOperators++;
        } else {
            throw std::runtime_error("Error: Invalid character");
        }
    }

    if (stack.size() != 1 || countNumbers - 1 != countOperators) {
        throw std::runtime_error("Error: Malformed expression");
    }

    return stack.top();
}
