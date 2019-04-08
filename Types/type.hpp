#ifndef TYPE_HPP
#define TYPE_HPP

class Type{
public:
    virtual int Size() = 0;
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