#include "stringlist.hpp"

int StringList::add(std::string s){
    int length = strvect.size();
    strvect.push_back(s);
    return length;
}