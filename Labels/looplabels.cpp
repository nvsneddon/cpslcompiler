#include "looplabels.hpp"

int LoopLabels::WhileLabel(){
    static int label = 0;
    return label++;
}

int LoopLabels::IfLabel(){
    static int label = 0;
    return label++;
}