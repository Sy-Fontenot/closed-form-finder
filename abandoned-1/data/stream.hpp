#ifndef STREAM
#define STREAM

#include <iostream>
#include <vector>
#include "stream-operand.hpp"
#include "stream-operator.hpp"

class Stream : StreamOperand {
    private:
        // RESTRUCTURE AS SINGLE VECTOR OF OBJECTS?
        std::vector<StreamOperand*> streamOperands;
        std::vector<StreamOperator*> streamOperators;
        short streamOperandCount;   // streamOperatorCount = streamOperandCount - 1
    public:
        Stream(StreamOperand*);
        ~Stream();
        void PrependStream(StreamOperand*, StreamOperator*);
        void AppendStream(StreamOperator*, StreamOperand*);
        void AddIndexedStream(StreamOperand*, StreamOperator*, short);
        void DeleteIndexedStream(short);
        void MutateStream(short);
            //opr
            //opd
            //randomize
            //nested
        void RandomReset();
        Stream* GenerateRandomStream();

        void PrintStream();
        void PrintOperators();
        void PrintOperands();
};

#endif