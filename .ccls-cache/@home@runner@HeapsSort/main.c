#include <stdio.h>
#include <stdlib.h>

void BuildHeap(int A[], int currentSize);
void PercolateDown(int A[], int hole, int currentSize);
void PercolateUp(int A[], int hole);
void ExtractMin(int A[], int *currentSize);
void HeapSort(int A[], int currentSize);

int main(void)
{
    int A[106], i, currentSize;
    for (i = 1; i <= 100; i++) {
        A[i] = rand();
    }
    currentSize = 100;
    HeapSort(A, currentSize);

    // Print sorted array
    for (i = 1; i <= currentSize; i++) {
        printf("%d ", A[i]);
    }
    return 0;
}

void HeapSort(int A[], int currentSize)
{
    BuildHeap(A, currentSize);
    for (int i = currentSize; i > 1; i--) {
        ExtractMin(A, &i);
    }
}

void PercolateDown(int A[], int hole, int currentSize)
{
    int temp = A[hole];
    int child;

    while (hole * 2 <= currentSize) {
        child = hole * 2;

        // Find the smaller child
        if (child != currentSize && A[child + 1] < A[child]) {
            child = child + 1;
        }

        if (A[child] < temp) {
            A[hole] = A[child];
            hole = child;
        } else {
            break;
        }
    }

    A[hole] = temp;
}

void PercolateUp(int A[], int hole)
{
    while (hole > 1 && A[hole / 2] > A[hole]) {
        // Swap parent and child
        int temp = A[hole];
        A[hole] = A[hole / 2];
        A[hole / 2] = temp;

        hole = hole / 2;
    }
}

void BuildHeap(int A[], int currentSize)
{
    for (int i = currentSize / 2; i >= 1; i--) {
        PercolateDown(A, i, currentSize);
    }
}

void ExtractMin(int A[], int *currentSize)
{
    if (*currentSize < 1) {
        printf("Heap is empty\n");
        return;
    }

    // Swap the root(minimum element) with the last element
    int temp = A[1];
    A[1] = A[*currentSize];
    A[*currentSize] = temp;

    (*currentSize)--;

    // Restore heap property
    PercolateDown(A, 1, *currentSize);
}
