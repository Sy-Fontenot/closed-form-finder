#ifndef TERM
#define TERM

#include "stream-operand.hpp"

class Term : StreamOperand {
    private:
        int value;  // set to 0 if variable
    public:
        Term(/* args */);
        ~Term();
        void setValue(int);
        int getValue();
};

#endif