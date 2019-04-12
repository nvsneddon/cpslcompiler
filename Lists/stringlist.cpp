#include "stringlist.hpp"

StringList::StringList(){
    strvect.push_back("\"False\"");
    strvect.push_back("\"True\"");
}

int StringList::add(std::string s){
    int length = strvect.size();
    for (int i = 0; i < s.length(); i++){
        if (s[i] == '\n'){
            s.erase(i, 1);
            s.insert(i, "\\n");
        }
    }
    strvect.push_back(s);
    return length;
}

void StringList::printLabels(){
    std::cout << ".data" << std::endl;
    for(int i = 0; i < strvect.size(); i++){
        std::cout << "string" << i << ": .asciiz " << strvect[i] << std::endl;
    }
}