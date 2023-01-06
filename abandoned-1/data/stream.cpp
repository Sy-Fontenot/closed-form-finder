#include "stream.hpp"

Stream::Stream(StreamOperand* streamOperand) {
    streamOperands.push_back(streamOperand);
    streamOperandCount = 1;
}

Stream::~Stream() {
    if (streamOperands.size() > 0) {
        int size = streamOperators.size();
        for (int i = 0; i < size - 1; i++) {
            delete streamOperators.at(i);
            delete streamOperands.at(i);
        }
        delete streamOperands.at(size);
    }
}

void Stream::PrependStream(StreamOperand* streamOperand, StreamOperator* streamOperator) {
    if (streamOperandCount <= 0) {
        std::cerr << "Stream must have an existing element to prepend to.\n";
        return;
    }

    streamOperators.insert(streamOperators.begin(), streamOperator);
    streamOperands.insert(streamOperands.begin(), streamOperand);

    streamOperandCount++;
}

void Stream::AppendStream(StreamOperator* streamOperator, StreamOperand* streamOperand) {
    if (streamOperandCount <= 0) {
        std::cerr << "Stream must have an existing element to append to.\n";
        return;
    }

    streamOperators.push_back(streamOperator);
    streamOperands.push_back(streamOperand);

    streamOperandCount++;
}

void Stream::AddIndexedStream(StreamOperand* streamOperand, StreamOperator* streamOperator, short index) {
    if (streamOperandCount <= 0) {
        std::cerr << "Stream must have an existing element to add to.\n";
        return;
    }
    if (index < 0 || index >= streamOperandCount) {
        std::cerr << "Index is out of bounds.\n";
        return;
    }

    streamOperators.insert(streamOperators.begin() + index, streamOperator);
    streamOperands.insert(streamOperands.begin() + index, streamOperand);

    streamOperandCount++;
}

void Stream::DeleteIndexedStream(short index) {
    if (streamOperandCount <= 0) {
        std::cerr << "Stream must have an existing element to delete.\n";
        return;
    }
    if (index < 0 || index >= streamOperandCount) {
        std::cerr << "Index is out of bounds.\n";
        return;
    }

    streamOperators.erase(streamOperators.begin() + index);
    streamOperands.erase(streamOperands.begin() + index);

    streamOperandCount--;
}

void Stream::MutateStream(short) {
    
}

void Stream::RandomReset() {
    
}

void Stream::PrintStream() {
    if (streamOperands.size() > 0) {
        int size = streamOperators.size();
        for (int i = 0; i < size; i++)
            std::cout << streamOperands.at(i)->GetTemp() << " (" << streamOperators.at(i)->GetTemp() << ") ";
        std::cout << streamOperands.at(size)->GetTemp() << std::endl;
    }
}

void Stream::PrintOperators() {
    std::cout << "Size : " << streamOperators.size() << std::endl;
    std::cout << "Operators : (";
    for (unsigned int i = 0; i < streamOperators.size(); i++)
        std::cout << streamOperators.at(i)->GetTemp();
    std::cout << ")\n";
}

void Stream::PrintOperands() {
    std::cout << "Size : " << streamOperands.size() << std::endl;
    std::cout << "Operands : [";
    for (unsigned int i = 0; i < streamOperands.size(); i++)
        std::cout << streamOperands.at(i)->GetTemp();
    std::cout << "]\n";
}
