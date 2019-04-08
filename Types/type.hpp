#ifndef TYPE_HPP
#define TYPE_HPP

class Type{
public:
private:
protected:
};

class Array : public Type{
public:
    int size();
private:
    int lb;
    int ub;
};  

#endif