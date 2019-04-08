#ifndef SIMPLE_TYPE_HPP
#define SIMPLE_TYPE_HPP

#include "type.hpp"

class SimpleType {
public:
    SimpleType() {};
    virtual int size();
private:
protected:
};

class Integer : public SimpleType{
public:
    Integer() : SimpleType() {};
private:
};

class Character : public SimpleType{
public:
    Character() : SimpleType() {};
private:
};

class CharacterString : public SimpleType{
public:
private:
};

class Bool : public SimpleType{
public:
    Bool() : SimpleType() {};
private:
};

#endif