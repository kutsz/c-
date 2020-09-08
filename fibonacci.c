#include <stdio.h>
#include <malloc.h>

int fibRec(int* cache, int n);

int fibIter(int* fibarr, int n);

void allEl_0(int* arr, int n);

void show(int* arr, int n);

int main()
{
    int n;

    printf("Enter amount of Fibonacci numbers (int): ");
    scanf("%d", &n);
//--------------------
    int* array = malloc(n*sizeof(int));
    allEl_0(array, n);
    printf("Recursion: ");

    array[1] = 1;
    fibRec(array, n-1);

    show(array, n);
//----------------------
    printf("\n");
//-----------------------
    int* arr = malloc(n*sizeof(int));
   // allEl_0(arr, n);
    printf("Iteration: ");

    fibIter(arr, n);

    show(arr, n);
//----------------------
    free(array);
    free(arr);

    printf("\n");

    return 0;
}

int fibRec(int* cache, int n)
{
//    cache[1] = 1;
    if (n <= 1)
        return n;
    if (cache[n] == 0) {
        cache[n] = fibRec(cache, n-1)+fibRec(cache, n-2);
    }

    return cache[n];
}

void allEl_0(int* arr, int n)
{
    for (int i = 0; i<n; i++)
        arr[i] = 0;
}

int fibIter(int* fibarr, int n)
{
    fibarr[0] = 0;
    fibarr[1] = 1;

    for (int i = 2; i<n; i++)
        fibarr[i] = fibarr[i-1]+fibarr[i-2];

    return fibarr[n];
}

void show(int* arr, int n)
{
    for (int i = 0; i<n; i++)
        printf("%d ", arr[i]);
}
