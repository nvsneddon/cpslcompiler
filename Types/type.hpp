#ifndef TYPE_HPP
#define TYPE_HPP

class Type{
public:
    Type(int e) { element = e; };
    virtual int size();
    virtual int getExpression() { return element; }
private:
protected:
    int element;
};

class Integer : public Type{
public:
    Integer(int e) : Type(e) {};
private:
};

class Character : public Type{
public:
    Character(int e) : Type(e) {};
private:
};

class CharacterString : public Type{
public:
private:
};

class Bool : public Type{
public:
    Bool(int e) : Type(e) {};
private:
};

class Array : public Type{
public:
    int size();
private:
    int lb;
    int ub;
};  

#endif