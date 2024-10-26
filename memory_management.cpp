#include <iostream>

using namespace std;

int globalInitialized1 = 100;
int globalInitialized2 = 200;
int globalInitialized3 = 300;

int globalUninitialized1;
int globalUninitialized2;
int globalUninitialized3;

int stack(int x) {
    int localVar = x * 2;

    printf("Stack address = %p and value = %d\n", &localVar, localVar);
    
    if (x == 0) return 0;

    return stack(x - 1);
}

int main(){
    stack(5);
    printf("\n");

    int *heap1 = new int();
    int *heap2 = new int();
    int *heap3 = new int();

    *heap1 = 10;
    *heap2 = 20;
    *heap3 = 30;

    printf("Heap address 1 = %p and value = %d\n", heap1, *heap1);
    printf("Heap address 2 = %p and value = %d\n", heap2, *heap2);
    printf("Heap address 3 = %p and value = %d\n", heap3, *heap3);
    printf("\n");

    int size = 5;
    int *heapArray = new int[size];

    for (int i = 0; i < size; ++i) {
        heapArray[i] = (i + 1) * 10;
        printf("Heap array address %d = %p and value = %d\n",i , &heapArray[i], heapArray[i]);
    }
    printf("\n");

    printf("Global initialized address 1 = %p and value = %d\n",&globalInitialized1, globalInitialized1);
    printf("Global initialized address 2 = %p and value = %d\n",&globalInitialized2, globalInitialized2);
    printf("Global initialized address 3 = %p and value = %d\n",&globalInitialized3, globalInitialized3);
    printf("Global uninitialized address 1 = %p and value = %d\n", &globalUninitialized1, globalUninitialized1);
    printf("Global uninitialized address 2 = %p and value = %d\n", &globalUninitialized2, globalUninitialized2);
    printf("Global uninitialized address 3 = %p and value = %d\n", &globalUninitialized3, globalUninitialized3);
    printf("\n");

    delete heap1;
    delete heap2;
    delete heap3;
    delete[] heapArray;

    return 0;
}