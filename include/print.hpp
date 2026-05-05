#ifndef PRINT_HPP
#define PRINT_HPP

#include <fstream>
#include <iostream>
#include <string>

void print(const std::string& text, std::ostream& out = std::cout);
void print(const int& number, std::ostream& out = std::cout);

#endif // PRINT_HPP
