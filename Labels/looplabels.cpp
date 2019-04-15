#include "looplabels.hpp"

int LoopLabels::whileLabel(){
    static int label = 0;
    return label++;
}

int LoopLabels::ifLabel(){
    return iflabel;
}


int LoopLabels::elseIfLabel(){
    return iflabel;
}

int LoopLabels::elseLabel(){
    return iflabel;
}