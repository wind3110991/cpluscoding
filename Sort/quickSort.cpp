#include <iostream>
using namespace std;

void myQuickSort(int a[], int start, int end){
	if (start >= end)
		return;

	int pivot = a[start];
	int leftIndex = start;
	int rightIndex = end;

	while(leftIndex < rightIndex){
		while(leftIndex < rightIndex){
			if (leftIndex < rightIndex && a[rightIndex] >= pivot){
				rightIndex--;
			}
			else{
				a[leftIndex++] = a[rightIndex];
				break;
			}
		}

		while(leftIndex < rightIndex){
			if (leftIndex < rightIndex && a[leftIndex] <= pivot){
				leftIndex++;
			}
			else{
				a[rightIndex--] = a[leftIndex];
				break;
			}

		}
	}

	a[leftIndex] = pivot;
	myQuickSort(a, start, leftIndex-1);
	myQuickSort(a, rightIndex+1, end);
}


int main()
{
    int arry[] = { 3, 21, 87, 1, 21, 10, 26 };
    int arryLength = sizeof(arry)/sizeof(int);

    myQuickSort(arry, 0, arryLength-1);

    for (int i = 0; i < arryLength; i++)
    {
        std::cout << arry[i] << " ";
    }
    std::cout<<endl;
    return 0;
}
