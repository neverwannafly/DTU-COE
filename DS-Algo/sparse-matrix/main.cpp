#include <iostream>
#define MAX_SIZE 1000
#define WIDTH 3

struct sparseMatrix {
    int vi[WIDTH][MAX_SIZE];
    int size;
    int row;
    int column;
};

void makeSparseMatrix(int *matrix, sparseMatrix &sm, int N, int M) {
    sm.size = 0;
    sm.row = N;
    sm.column = M;
    int counter = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (*((matrix + i*M) + j)!=0 && sm.size < MAX_SIZE) {
                sm.vi[0][counter] = i;
                sm.vi[1][counter] = j;
                sm.vi[2][counter] = *((matrix + i*M) + j);
                counter++;
            }
        }
    }
    sm.size = counter;
}

void insert(const sparseMatrix &sm, sparseMatrix &result, int &counterResult, int &counterSm) {
    result.vi[0][counterResult] = sm.vi[0][counterSm];
    result.vi[1][counterResult] = sm.vi[1][counterSm];
    result.vi[2][counterResult++] = sm.vi[2][counterSm++];
}

sparseMatrix addMatrixes(const sparseMatrix &sm1, const sparseMatrix &sm2) {
    sparseMatrix result;
    result.size = 0;
    result.row = sm1.row;
    result.column = sm1.column;
    if (!(sm1.column==sm2.column && sm1.row==sm2.row)) {
        // return a 0x0 matrix if matrixes are incompitable
        result.row = 0;
        result.column = 0;
        return result;
    }
    int counterSm1 = 0;
    int counterSm2 = 0;
    int counterResult = 0;

    while (counterSm1 < sm1.size && counterSm2 < sm2.size) {
        if (sm1.vi[0][counterSm1] < sm2.vi[0][counterSm2]) {
            insert(sm1, result, counterResult, counterSm1);
        } 
        else if (sm1.vi[0][counterSm1] > sm2.vi[0][counterSm2]) {
            insert(sm2, result, counterResult, counterSm2);
        }
        else {
            if (sm1.vi[1][counterSm1] < sm2.vi[1][counterSm2]) {
                insert(sm1, result, counterResult, counterSm1);
            }
            else if (sm1.vi[1][counterSm1] > sm2.vi[1][counterSm2]) {
                insert(sm2, result, counterResult, counterSm2);
            }
            else {
                result.vi[0][counterResult] = sm2.vi[0][counterSm2];
                result.vi[1][counterResult] = sm2.vi[1][counterSm2];
                result.vi[2][counterResult++] = sm2.vi[2][counterSm2++] + sm1.vi[2][counterSm1++];
            }
        }
    } 

    while (counterSm1 < sm1.size) {
        insert(sm1, result, counterResult, counterSm1);
    }

    while (counterSm2 < sm2.size) {
        insert(sm2, result, counterResult, counterSm2);
    }

    result.size = counterResult;

    return result;
}

sparseMatrix transposeMatrix(sparseMatrix sm) {
    sparseMatrix result;
    result.row = sm.column;
    result.column = sm.row;
    result.size = sm.size;

    int count[sm.column];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < sm.size; i++) {
        count[sm.vi[1][i]]++;
    }

    int index[sm.column];

    index[0] = 0;

    for (int i = 1; i < sm.column; i++)  {
       index[i] = index[i-1] + count[i-1];
    }

    for (int i = 0; i < sm.size; i++) {
        int counter = index[sm.vi[1][i]]++;
        result.vi[0][counter] = sm.vi[1][i];
        result.vi[1][counter] = sm.vi[0][i];
        result.vi[2][counter] = sm.vi[2][i];
    }

    return result;
}

sparseMatrix multiplyMatrixes(const sparseMatrix &sm1, const sparseMatrix &sm2) {
    sparseMatrix result;
    result.size = 0;
    result.row = sm1.row;
    result.column = sm2.column;

    if (sm1.column != sm2.row) {
        result.row = 0;
        result.column = 0;
        return result;
    }

    sparseMatrix transposeSm2 = transposeMatrix(sm2);
    int counterSm1, counterTsm2;

    for (counterSm1 = 0; counterSm1 < sm1.size;) { 
  
        int r = sm1.vi[0][counterSm1]; 

        for (counterTsm2 = 0; counterTsm2 < transposeSm2.size;) { 

            int c = transposeSm2.vi[0][counterTsm2]; 

            int tempa = counterSm1; 
            int tempb = counterTsm2; 

            int sum = 0; 

            while (tempa < sm1.size && sm1.vi[0][tempa] == r 
                    && tempb < transposeSm2.size && transposeSm2.vi[0][tempb] == c) { 

                if (sm1.vi[1][tempa] < transposeSm2.vi[1][tempb]) {
                    tempa++; 
                }
                else if (sm1.vi[1][tempa] > transposeSm2.vi[1][tempb]) {
                    tempb++; 
                }
                else {
                    sum += sm1.vi[2][tempa++] * transposeSm2.vi[2][tempb++]; 
                }
            } 

            if (sum != 0) {
                result.vi[0][result.size] = r; 
                result.vi[1][result.size] = c; 
                result.vi[2][result.size] = sum; 
                result.size++;
            }

            while (counterTsm2 < transposeSm2.size && transposeSm2.vi[0][counterTsm2] == c) {
                counterTsm2++;
            }
        } 

        while (counterSm1 < sm1.size && sm1.vi[0][counterSm1] == r) {
            counterSm1++; 
        }
    } 

    return result;
}

void printSparseMatrix(const sparseMatrix &sm) {
    printf("---------------------------\n");
    for (int i=0; i<sm.size; i++) {
        for (int j=0; j<WIDTH; j++) {
            printf("%d ", sm.vi[j][i]);
        }
        printf("\n");
    }
    printf("---------------------------\n");
}

int main() {

    int arr1[3][3] = {
        {1, 0, 0},
        {0, 2, 0},
        {3, 0, 0},
    };

    int arr2[3][3] = {
        {0, 1, 2},
        {0, 0, 0},
        {1, 0, 0},
    };

    sparseMatrix sm1, sm2, result;
    makeSparseMatrix((int *)arr1, sm1, 3, 3);
    makeSparseMatrix((int *)arr2, sm2, 3, 3);
    printSparseMatrix(sm1);
    printSparseMatrix(sm2);
    result = addMatrixes(sm1, sm2);
    printSparseMatrix(result);

    result = transposeMatrix(sm2);
    printSparseMatrix(result);

    result = multiplyMatrixes(sm1, sm2);
    printSparseMatrix(result);

    return 0;
}