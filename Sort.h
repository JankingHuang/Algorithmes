#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <cassert>
using namespace std;
namespace Sort
{
    template<typename T>
    void selectionSort(T arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            int minIndex = i;
            for (int j = i + 1; j < n; j++)
                if (arr[j] < arr[minIndex])
                    minIndex = j;
            swap(arr[i], arr[minIndex]);
        }
    }

    template<typename T>
    void insertionSort(T arr[], int n){
        for(int i = 1; i < n; i++){
            for(int j = i; j > 0; j--){
                if(arr[j] < arr[j - 1])
                    swap(arr[j], arr[j - 1]);
                else
                    break;
            }
        }
    }

    template<typename T>
    void insertionSortPlus(T arr[], int n){
        //可以结束内层循环，对近乎有序的情况，效率非常高
        for(int i = 1; i < n; i++){
            T e = arr[i];
            int j;
            for(j = i; j > 0; j--){
                if(arr[j - 1] > e)
                    arr[j] = arr[j - 1];
                else
                    break;
            }
            arr[j] = e;
        }
    }
    
    //将arr[l,mid] ，arr[mid+1,r] 合并
    template<typename T>
    void __merge(T arr[], int l, int mid, int r){
        T aux[r - l + 1];
        for(int i = l; i <= r; i++)
            aux[i - l] = arr[i];
        int i = l, j = mid + 1;
        for(int k = l; k <= r; k++){
            if(i > mid){
                arr[k] = aux[j - l];
                j++;
            }else if(j > r){
                arr[k] = aux[i - l];
                i++;
            }
            else if(aux[i - l] < aux[j - l]){
                arr[k] = aux[i - l];
            }else{
                arr[k] = aux[j - l];
                j++;
            }
        }
    }

    //进行划分
    template<typename T> //对arr[l,r]范围
    void __mergeSort(T arr[], int l, int r){
        if(l >= r)
            return;
        int mid = (l + r) / 2;
        __mergeSort(arr, l, mid);
        __mergeSort(arr, mid + 1, r);
        if( arr[mid] > arr[mid+1])
            __merge(arr, l, mid, r);
    }

    template<typename T>
    void mergeSort(T arr[], int n){
        __mergeSort(arr, 0, n-1);
    }
} // namespace Sort

#endif

