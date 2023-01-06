#include "stream-operator.hpp"

StreamOperator::StreamOperator() {

}

StreamOperator::StreamOperator(int t)
{
    temp = t;
}

StreamOperator::~StreamOperator() {

}

int StreamOperator::GetTemp() {
    return temp;
}
