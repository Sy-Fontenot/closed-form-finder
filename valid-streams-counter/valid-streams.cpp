#include <iostream>
#include <string>

long long CalcIndex(short,short,long long*,int);

int main(int agrc, char** argv) {

    int max = std::stoi(argv[1]);

    long long* validCountMatrix = new long long[max * max]{0};
    validCountMatrix[0] = 1;

    for (short i = 0; i < max; i++) {
        for (short j = 0; j <= i; j++) {
            validCountMatrix[i + j * max] += CalcIndex(i, j, validCountMatrix, max);
            if (i != j)
                validCountMatrix[j + i * max] += CalcIndex(j, i, validCountMatrix, max);
        }
    }

    for (int i = 0; i < max; i++) {
        std::cout << "Size " << 2 * i + 1 << " : " << validCountMatrix[i + i * max] << std::endl;
        if (i < max - 1)
            std::cout << "Size " << 2 * (i + 1) << " : " << validCountMatrix[i + (i + 1) * max] << std::endl;
    }

    delete validCountMatrix;

    return 0;
}

long long CalcIndex(short col, short row, long long* matrix, int max) {
    long long abov = row > 0 ? matrix[col + (row - 1) * max] : 0;
    long long left = col > 0 ? matrix[(col - 1) + row * max] : 0;
    long long refl = row > 0 && !(row - col == 1 || row == col) ? matrix[(row - 1) + col * max] : 0;
    return abov + left + refl;
}