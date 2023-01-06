#ifndef STREAM_OPERAND
#define STREAM_OPERAND

class StreamOperand {
    private:
        int temp;
    public:
        StreamOperand();
        StreamOperand(int);
        ~StreamOperand();
        int GetTemp();
};

#endif