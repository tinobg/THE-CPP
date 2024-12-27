#include "Harl.hpp"
#include <iostream>
#include <string>

void Harl::debug() {
    std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
}

void Harl::info() {
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning() {
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error() {
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(const std::string& level) {
    typedef void (Harl::*HarlFunction)();
    const std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
    HarlFunction functions[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (size_t i = 0; i < 4; ++i) {
        if (levels[i] == level) {
            (this->*functions[i])();
            return;
        }
    }
    std::cout << "[ UNKNOWN LEVEL ]\nNo complaints to display.\n" << std::endl;
}