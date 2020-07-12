#include <iostream>
#include "SortTestHelper.h"
#include "Sort.h"
using namespace std;

int main()
{
    int n = 500000;
    // int *arr = SortTestHelper::generateNearlyOrderArray(n,10);
    int *arr = SortTestHelper::generateRandomArray(0,n,n);

    int *arr1 = SortTestHelper::copyInArray(arr,n);
    int *arr2 = SortTestHelper::copyInArray(arr,n);
    int *arr3 = SortTestHelper::copyInArray(arr,n);
    SortTestHelper::testSort("Selection sort",Sort::selectionSort,arr,n);
    SortTestHelper::testSort("Insertion sort",Sort::insertionSort,arr1,n);
    SortTestHelper::testSort("InsertionPlus sort",Sort::insertionSortPlus,arr2,n);
    SortTestHelper::testSort("Merge sort",Sort::mergeSort,arr3,n);

    return 0;
}