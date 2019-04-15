#include "record.hpp"

Record::Record() : Record("$gp") {}

Record::Record(std::string r){
    refPointer = r;
}

int Record::size(){
    int s = 0;
    for (auto it = types.begin(); it != types.end(); it++) {
       s += it->second->size(); 
    }
    return s;
}

void Record::addType(std::string label, Type* t){
    int newsize = size();
    types.insert(std::make_pair(label, t));
    indexnumber.insert(std::make_pair(label, newsize));
}

Type* Record::getTypeInRecord(std::string label){
    auto it = types.find(label);
    if (it != types.end()){
        return it->second->getCopyPtr();
    }
    return NULL;
}
//TODO Fix this thing right here. This is going to be a hard one to figure out.
Type* Record::getCopyPtr(){
    Record* returnrecord = new Record();
    for(auto labelit = types.begin(); labelit != types.end(); labelit++){
        returnrecord->addType(labelit->first, labelit->second);
    }
    return returnrecord;
}

MemExpression* Record::getExpression(std::string label, int offset){
    auto it = types.find(label);
    auto it2 = indexnumber.find(label);
    if (it != types.end() && it2 != indexnumber.end()){
        return new MemExpression(it2->second, refPointer, it->second->getCopyPtr(), true);
    }
    return NULL;
}