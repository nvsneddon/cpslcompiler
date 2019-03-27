#include "type.hpp"

int Type::size(){
    return 4;
}

int Integer::size(){
    return 4;
}

int Character::size(){
    return 1;
}

int CharacterString::size(){
    return 0;
}

int Bool::size(){
    return 1;
}