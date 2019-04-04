#ifndef TYPE_HPP
#define TYPE_HPP

#include <string>

class Type{
public:
    Type() {};
    virtual int size();
private:
protected:
    int element;
};

class Integer : public Type{
public:
private:
};

class Character : public Type{
public:
private:
};

class CharacterString : public Type{
public:
private:
};

class Bool : public Type{
public:
private:
};

#endif