#ifndef STRING_EXPRESSION_HPP
#define STRING_EXPRESSION_HPP
#include <string>
#include <vector>

class StringList{
public:
    int add(std::string);
private:
    std::vector<std::string> strvect;
};

#endif