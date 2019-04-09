#ifndef SIMPLE_TYPE_HPP
#define SIMPLE_TYPE_HPP

#include "type.hpp"

class SimpleType : public Type {
public:
    SimpleType() {};
    virtual int size() { return 4; }
    virtual std::string getTypeAsString() = 0;
private:
protected:
};

class Integer : public SimpleType {
public:
    Integer() : SimpleType() {};
    std::string getTypeAsString() { return "integer"; };
private:
};

class Char : public SimpleType {
public:
    Char() : SimpleType() {};
    std::string getTypeAsString() { return "char"; };
private:
};

//Should I name this String or CharacterString?
class String : public SimpleType { 
public:
    std::string getTypeAsString() { return "string"; };
private:
};

class Boolean : public SimpleType {
public:
    Boolean() : SimpleType() {};
    std::string getTypeAsString() { return "boolean"; };
private:
};

#endif