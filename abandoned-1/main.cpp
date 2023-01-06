#include "data/stream.hpp"

int main () {

    StreamOperand* opd0 = new StreamOperand(0);
    StreamOperand* opd1 = new StreamOperand(1);

    StreamOperator* opr2 = new StreamOperator(2);
    StreamOperator* opr3 = new StreamOperator(3);

    // --- Phase 1 --- //
    std::cout << "\n -- Phase 1 --\n";

    Stream* stream1 = new Stream(opd1);
    Stream* stream2 = new Stream(opd0);

    std::cout << "Stream 1 : ";
    stream1->PrintStream();
    std::cout << "Stream 2 : ";
    stream2->PrintStream();

    // --- Phase 2 --- //
    std::cout << "\n -- Phase 2 --\n";

    stream1->AppendStream(opr2, opd1);

    stream2->AppendStream(opr3, opd1);
    stream2->AppendStream(opr2, opd0);

    std::cout << "Stream 1 : ";
    stream1->PrintStream();
    std::cout << "Stream 2 : ";
    stream2->PrintStream();

    // --- Phase 3 --- //
    std::cout << "\n -- Phase 3 --\n";

    stream1->AddIndexedStream(opd1, opr3, 0);
    stream2->AddIndexedStream(opd0, opr2, 1);

    std::cout << "Stream 1 : ";
    stream1->PrintStream();
    std::cout << "Stream 2 : ";
    stream2->PrintStream();

    return 0;
}