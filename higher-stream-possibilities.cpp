#include <iostream>
#include <string>

bool checkHStream(short*, short);
short* incrStream(short*, short);
void printHStream(short*, short);

int main(int agrc, char** argv) {

    int max = std::stoi(argv[1]);

    for (int i = 1; i <= max; i++) {
        int accumulation = 0;
        short* hStream = new short[i];

        long long runs = 1;
        for (int r = 1; r < i; r++)
            runs *= 3;

        for (long long j = 0; j < runs; j++) {
            if (checkHStream(hStream, i))
                accumulation++;
            hStream = incrStream(hStream, i);
        }

        std::cout << "Size : " << i << " Valid Count : " << accumulation << std::endl;

        delete hStream;
    }
    return 0;
}

bool checkHStream(short* input, short size) {
    short operandCount = 0;
    short binOpCount = 0;

    for (int i = 0; i < size; i++) {
        if (input[i] == 0)
            operandCount++;
        if (input[i] == 2)
            binOpCount++;
        if (binOpCount >= operandCount)
            return false;
    }

    if (operandCount - binOpCount != 1)
        return false;

    return true;
}

short* incrStream(short* input, short size) {
    short index = size;
    while (--index > 0)
        if ((input[index] = (input[index] + 1) % 3) > 0)
            return input;
    return input;
}

void printHStream(short* input, short size) {
    for (int i = 0; i < size; i++)
        std::cout << input[i] << ' ';
    std::cout << std::endl;
}