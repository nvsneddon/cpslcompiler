#ifndef LOOPLABELS_HPP
#define LOOPLABELS_HPP
#include <string>

class LoopLabels{
public:
    LoopLabels() : iflabel(0), endlabelnr(0) {}
    static int whileLabel();
    int ifLabel();
    int elseIfLabel();
    int elseLabel();
    //void resetEndLabel() { labelnr = 0; }
    void incEndLabel() { endlabelnr++; }
    void incIfLabel() { iflabel++; }
    std::string getEndLabel() { return "end" + endlabelnr; }
private:
    int endlabelnr;
    int iflabel;
};

#endif 