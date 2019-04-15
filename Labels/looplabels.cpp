#include "looplabels.hpp"

int LoopLabels::whileLabel(){
    static int label = 0;
    return label++;
}

int LoopLabels::ifLabel(){
    return iflabel++;
}


int LoopLabels::elseIfLabel(){
    return iflabel++;
}

int LoopLabels::elseLabel(){
    int iflabel = 0;
    return iflabel++;
}