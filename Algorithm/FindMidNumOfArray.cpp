#include<iostream>
#include<cstdlib>
using namespace std;

void genMaxHeap(int a[], int len, int index)
{
    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;
    int maxIndex = index;

    if (leftIndex < len && a[maxIndex] < a[leftIndex])
        maxIndex = leftIndex;
    if (rightIndex < len && a[maxIndex] < a[rightIndex])
        maxIndex = rightIndex;

    if (maxIndex != index)
    {
        swap(a[maxIndex], a[index]);
        genMaxHeap(a, len, maxIndex);
    }
}

void heapSort(int a[], int len)
{
    for (int i = len/2-1; i >= 0; i--)
    {
        genMaxHeap(a, len, i);
    }

    for (int i = len-1; i > 0; i--)
    {
        swap(a[0], a[i]);
        genMaxHeap(a, i, 0);
    }
}

/* find the mid number of a unsorted array */
void findMidNumber(int a[], int len)
{
    for (int i = len/2-1; i >= 0; i--)
    {
        genMaxHeap(a, len, i);
    }

    int mid = 0;
    for (int i = len-1; i > len/2; i--)
    {
        swap(a[0], a[i]);
        genMaxHeap(a, i, 0);

        mid = a[0];
    }

    cout<<"mid:"<<a[0]<<endl;
}

int main()
{
    int a[] = {31, 5, 1, 8, 10, 9, 100, 99, 16, 2, 63};
    int len = sizeof(a) / sizeof(int);
    findMidNumber(a, len);

    for (int i = 0 ; i < len; i++)
    {
        cout<<a[i]<<" ";
    }

    return 0;
}
