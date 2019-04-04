#ifndef TYPE_HPP
#define TYPE_HPP

class Type{
public:
    Type() {};
    virtual int size();
private:
protected:
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

class Boolean : public Type{
public:
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