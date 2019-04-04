#ifndef TYPE_HPP
#define TYPE_HPP

#include <string>

class Type{
public:
    Type() {};
    virtual int size();
private:
protected:
    std::string element;
};

class Integer : public Type{
public:
    int size();
private:
};

class Character : public Type{
public:
    int size();
private:
};

class CharacterString : public Type{
public:
    int size();
private:
};

class Bool : public Type{
public:
    int size();
private:
    bool element;
};

#endif