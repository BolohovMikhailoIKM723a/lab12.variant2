#include <iostream>
#include <stdlib.h> 


using namespace std;
const int SIZE = 5;
void createAndPrintMatrix(int matrix[SIZE][SIZE]) {
    cout << "матриця " << SIZE << "x" << SIZE << ":\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            matrix[i][j] = rand() % 21 - 10;
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
void matrixTo1DArray(int matrix[SIZE][SIZE], int array[SIZE * SIZE]) {
    int index = 0;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            array[index++] = matrix[i][j];
        }
    }
}
int findMaxElement(int array[], int size) {
    int maxElement = array[0];
    for (int i = 1; i < size; ++i) {
        if (array[i] > maxElement) {
            maxElement = array[i];
        }
    }
    return maxElement;
}
int main() {
    setlocale(LC_CTYPE, "ukr");
    int matrix[SIZE][SIZE];
    createAndPrintMatrix(matrix);

    int sumPositiveRows = 0;
    for (int i = 0; i < SIZE; ++i) {
        bool allPositive = true;
        for (int j = 0; j < SIZE; ++j) {
            if (matrix[i][j] <= 0) {
                allPositive = false;
                break;
            }
        }
        if (allPositive) {
            for (int j = 0; j < SIZE; ++j) {
                sumPositiveRows += matrix[i][j];
            }
        }
    }
    cout << "сума елементiв у рядках з додатнiми числами: " << sumPositiveRows << endl;
    int array[SIZE * SIZE];
    matrixTo1DArray(matrix, array);
    int maxElement = findMaxElement(array, SIZE * SIZE);
    cout << "максимальний елемент в одномiрному масивi: " << maxElement << endl;
    return 0;
}