#ifndef TYPE_HPP
#define TYPE_HPP

#include <string>

class Type{
public:
    virtual int size() = 0;
    virtual Type* getCopyPtr() = 0;
    virtual std::string getTypeAsString() = 0;
private:
protected:
};

//class Array : public Type{
//public:
//    int size() { return 4;  }; //Change this when you get arrays working
//private:
//    int lb;
//    int ub;
//};  

#endif