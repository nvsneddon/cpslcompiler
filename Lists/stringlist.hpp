#ifndef STRING_EXPRESSION_HPP
#define STRING_EXPRESSION_HPP
#include <string>
#include <vector>
#include <iostream>

class StringList{
public:
    StringList();
    int add(std::string);
    void printLabels();
private:
    std::vector<std::string> strvect;
};

#endif