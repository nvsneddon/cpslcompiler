#include "looplabels.hpp"

int LoopLabels::whileLabel(){
    static int label = 0;
    return label++;
}

int LoopLabels::repeatLabel(){
    static int label = 0;
    return label++;
}

int LoopLabels::ifLabel(){
    return iflabel;
}

int LoopLabels::forLabel(){
    static int lbl = 0;
    return lbl++;
}

int LoopLabels::elseIfLabel(){
    return iflabel;
}

int LoopLabels::elseLabel(){
    return iflabel;
}