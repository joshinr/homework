#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int leftSize = m - l + 1;
    int rightSize = r - m;
    
    int *leftArr = new int[leftSize];
    for (int i = 0; i < leftSize; ++i)
    {
        leftArr[i] = arr[l + i];
    }
    
    int *rightArr = new int[rightSize];
    for (int i = 0; i < rightSize; ++i)
    {
        rightArr[i] = arr[m + 1 + i];
    }
    
    int i=0;
    int j=0;
    int k = l;
    
    while(i < leftSize && j < rightSize)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k++] = leftArr[i++];
        }
        else
        {
            arr[k++] = rightArr[j++];
        }
    }
        
    while (i < leftSize)
    {
        arr[k++] = leftArr[i++];
    }
    
    while (j < rightSize)
    {
        arr[k++] = rightArr[j++];
    }
    
    delete []leftArr;
    delete []rightArr;
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main()
{
   int arr[] = {1,9,3,4,8};
   
   for (int i=0; i<5; ++i) 
   {
       cout<<arr[i]<<" ";
   }
   cout<<endl;
   
   mergeSort(arr, 0, 4);
   
   for (int i=0; i<5; ++i) 
   {
       cout<<arr[i]<<" ";
   }
   cout<<endl;
   
   return 0;
}