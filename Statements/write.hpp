#ifndef WRITE_HPP
#define WRITE_HPP
#include <string>
#include "statement.hpp"

class Write : public Statement{
    public:
        static void write(std::string msg);
        static void comment(std::string msg);
    private:
};
#endif
