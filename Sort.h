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
        //当数据趋于有序时，调用另一种算法进行排序。如插入排序
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

    template<typename T>
    void mergeSortBlowToUp(T arr[], int n){
        //没有使用数组空间，可以很好的对链表进行排序
        for( int sz = 1; sz <= n; sz += sz)
            for(int i = 0; i + sz < n; i += sz + sz)
                __merge(arr, i, i + sz - 1, min(i + sz + sz -1,n-1));
    }

    //返回p,使得arr[l, p - 1] < arr[p] ; arr[p + 1, r] > arr[p]
    template<typename T>
    int __partition(T arr[], int l, int r){
        swap(arr[l], arr[rand() % (r - l +1) + l]);//选择随机标定
        T v = arr[l];
        int j = l;
        for(int i = l + 1; i <= r; i++){
            if(arr[i] < v){
                swap(arr[j + 1], arr[i]);
                j++;
                //swap(arr[++j],arr[i]);
            }
        }
        swap(arr[l], arr[j]);
        return j;
    }

    template<typename T>
    void __quickSort(T arr[], int l, int r){
        if( l >= r){
            return;
        }
        int p = __partition(arr, l, r);
        __quickSort(arr, l, p - 1);
        __quickSort(arr, p + 1, r);
    }
    
    template<typename T>
    void quickSort(T arr[], int n){
        __quickSort(arr,0, n - 1);
    }
    

} // namespace Sort

#endif

