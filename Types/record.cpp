#include "record.hpp"

int Record::size(){
    int s = 0;
    for (auto it = types.begin(); it != types.end(); it++) {
       s += it->second->size(); 
    }
    return s;
}

void Record::addType(std::string label, Type* t){
    types.insert(std::make_pair(label, t));
}

Type* Record::getType(std::string label){
    auto it = types.find(label);
    if (it != types.end()){
        return it->second->getCopyPtr();
    }
    return NULL;
}