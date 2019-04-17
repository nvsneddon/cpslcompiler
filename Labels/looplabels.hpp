#ifndef LOOPLABELS_HPP
#define LOOPLABELS_HPP
#include <string>
#include <iostream>
#include <sstream>
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
    std::string getEndLabel() {
        std::stringstream s;
        //std::cerr << endlabeldeque[0] << " is end of deque\n";
        //std::cerr << "end" + endlabeldeque[0] << std::endl;
        //if("end" + endlabeldeque[0] == "")
        //    std::cerr << "This is very confusing\n";
        //std::cerr << "I think that this should be end" << endlabeldeque[0] << std::endl;
        s << "end" << endlabeldeque[0];
        return s.str(); 
        }
private:
    std::deque<int> endlabeldeque;
    int endlabelnr;
    int iflabel;
};

#endif 