#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int *num1, int *num2);

int main(int argc, char *argv[]) {
    int SIZE = 1 << 8;
    int A[SIZE];
    
    for (int i = 0; i < SIZE; i++) {
        A[i] = rand() % SIZE;
    }
    
    int N = SIZE;
    double start, end;
    
    start = omp_get_wtime();
    
    #pragma omp parallel
    {
        for (int i = 0; i < N - 1; i++) {
            #pragma omp for
            for (int j = 0; j < N - i - 1; j++) {
                if (A[j] > A[j + 1]) {
                    swap(&A[j], &A[j + 1]);
                }
            }
        }
    }
    
    end = omp_get_wtime();
    
    printf("Sorted array:");
    for (int i = 0; i < N; i++) {
        printf(" %d", A[i]);
    }
    printf("\n-------------------------\nTime Parallel= %f", (end - start));
    
    return 0;
}

void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
