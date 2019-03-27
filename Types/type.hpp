class Type{
public:
    virtual int size();
private:
protected:
};

class Integer : public Type{
public:
    int size();
};

class Character : public Type{
public:
    int size();
};

class CharacterString : public Type{
public:
    int size();
};

class Bool : public Type{
public:
    int size();
};