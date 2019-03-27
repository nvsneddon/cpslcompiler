#include "write.hpp"
#include <iostream>
#include <string>

using namespace std;

void Write::write(std::string msg){
    static int counter = 0;
    for (int i = 0; i < msg.length(); i++){
        if (msg[i] == '\n'){
            msg.erase(i, 1);
            msg.insert(i, "\\n");
            i++;
        }
    }
    string label = "msg" + to_string(counter++);
    cout << ".data" << endl;
    cout << label << ": .ascii \"" << msg << "\\0\"" << endl;
    cout << ".text" << endl;
    cout << "li $v0, 4" << endl;
    cout << "la $a0, " << label << endl;
    cout << "syscall" << endl;
}

