#ifndef STREAM_OPERATOR
#define STREAM_OPERATOR

class StreamOperator {
    private:
        int temp;
    public:
        StreamOperator();
        StreamOperator(int);
        ~StreamOperator();
        static void* functionList();
        int GetTemp();
};

#endif