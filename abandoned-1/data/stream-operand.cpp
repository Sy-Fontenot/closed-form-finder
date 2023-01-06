#include "stream-operand.hpp"

StreamOperand::StreamOperand() {

}

StreamOperand::StreamOperand(int t) {
    temp = t;
}

StreamOperand::~StreamOperand() {
    
}

int StreamOperand::GetTemp() {
    return temp;
}
