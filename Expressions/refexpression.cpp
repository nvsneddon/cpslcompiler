#include "refexpression.hpp"

RefExpression::RefExpression(int o, std::string p, Type* t) : MemExpression(o, p, t) {}

RefExpression::RefExpression(int o, Type* t) : MemExpression(o, "$fp", t) {}