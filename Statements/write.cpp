#include "write.hpp"
#include <iostream>
#include <string>
#include "../includes.hpp"


void Write::write(std::string msg){
    static int counter = 0;
    for (int i = 0; i < msg.length(); i++){
        if (msg[i] == '\n'){
            msg.erase(i, 1);
            msg.insert(i, "\\n");
        }
    }
    std::string label = "msg" + std::to_string(counter++);
    std::cout << ".data" << std::endl;
    std::cout << label << ": .asciiz \"" << msg << "\"" << std::endl;
    std::cout << ".text" << std::endl;
    std::cout << "li $v0, 4" << std::endl;
    std::cout << "la $a0, " << label << std::endl;
    std::cout << "syscall" << std::endl;
}

