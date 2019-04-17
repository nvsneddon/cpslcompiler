#ifndef LOOPLABELS_HPP
#define LOOPLABELS_HPP
#include <string>
#include <deque>

class LoopLabels{
public:
    LoopLabels() : iflabel(0), endlabelnr(0) {}
    static int whileLabel();
    static int repeatLabel();
    static int forLabel();
    int ifLabel();
    int elseIfLabel();
    int elseLabel();
    //void resetEndLabel() { labelnr = 0; }
    void startEndLabel() { endlabeldeque.push_front(endlabelnr++); } 
    void incIfLabel() { iflabel++; }
    void popEndLabel() { endlabeldeque.pop_front(); }
    std::string getEndLabel() { return "end" + endlabeldeque[0]; }
private:
    std::deque<int> endlabeldeque;
    int endlabelnr;
    int iflabel;
};

#endif 