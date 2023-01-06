#include "term.hpp"

Term::Term() {
    
}

Term::~Term() {
    
}

void Term::setValue(int value) {
    this->value = value;
}

int Term::getValue() {
    return value;
}