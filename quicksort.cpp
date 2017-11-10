// Example program
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(const vector<int> &arr)
{
    for (auto &n : arr)
    {
        cout << n << " ";
    }
    cout<<endl;
}

void swap(vector<int> &arr, int i, int j)
{
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

int partition(vector<int> &arr, int left, int right, int pivot)
{
    while(left < right)
    {
        while(arr[left] < pivot)
        {
            ++left;
        }
        
        while(arr[right] > pivot)
        {
            --right;
        }
        
        if(left <= right)
        {
            swap(arr, left, right);
            print(arr);
        }
    }
    return left;    
}

void quicksort(vector<int> &arr, int left, int right)
{
    if(left > right)
    {
        return;
    }
    
    int pivot = arr[(left+right)/2];
    int part = partition(arr, left, right, pivot);
    quicksort(arr, left, part-1);
    quicksort(arr, part+1, right);
}



int main()
{
  vector<int> arr = {5, 3, 1, 2, 8, 6};
  print(arr);
  quicksort(arr, 0, arr.size() - 1);
  print(arr);
}

