#ifndef SIMPLE_TYPE_HPP
#define SIMPLE_TYPE_HPP

#include "type.hpp"
#include <string>


class SimpleType : public Type {
public:
    SimpleType() : Type() {};
    virtual int size() { return 4; }
    virtual Type* getCopyPtr() = 0;
    virtual std::string getTypeAsString() = 0;
private:
protected:
};

class Integer : public SimpleType {
public:
    Integer() : SimpleType() {};
    std::string getTypeAsString() { return "integer"; };
    Type* getCopyPtr() { return new Integer(); };
private:
};

class Char : public SimpleType {
public:
    Char() : SimpleType() {};
    std::string getTypeAsString() { return "char"; };
    Type* getCopyPtr() { return new Char(); };
private:
};

class String : public SimpleType { 
public:
    String() : SimpleType() {};
    std::string getTypeAsString() { return "string"; };
    Type* getCopyPtr() { return new String(); };
private:
};

class Boolean : public SimpleType {
public:
    Boolean() : SimpleType() {};
    std::string getTypeAsString() { return "boolean"; };
    Type* getCopyPtr() { return new Boolean(); };
private:
};

#endif