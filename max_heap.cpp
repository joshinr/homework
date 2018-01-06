#include <iostream>
#include <vector>

using namespace std;


class MaxHeap 
{
private:
    vector<int> arr;

    int Left(int i)
    {
        return 2*i + 1;
    }

    int Right(int i)
    {
        return 2*i + 2;
    }

    int Parent(int i)
    {
        return (i-1)/2;
    }

    void HeapifyUp(int i)
    {
        if (i <= 0)
        {
            return;
        }

        int parent = Parent(i);

        if (arr[parent] < arr[i])
        {
            swap(arr[parent], arr[i]);
            HeapifyUp(parent);
        }
    }
    
    void HeapifyDown(int i, int n)
    {
        int left = Left(i);
        int right = Right(i);
        int largest = i;

        if (left < n && arr[left] > arr[largest])
        {
            largest = left;
        }

        if (right < n && arr[right] > arr[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            HeapifyDown(largest, n);
        }
    }

    void Print()
    {
        cout<<endl;
        for (auto &n : arr)
        {
            cout << n << " ";
        }
        cout<<endl;
    }
public:

    void Push(int i)
    {
        arr.push_back(i);
        HeapifyUp(Size() - 1);
    }

    void Pop()
    {
        if (arr.empty())
        {
            throw out_of_range("out of range");
        }

        int ret = arr[0];
        arr[0] = arr.back();
        arr.pop_back();
        HeapifyDown(0, Size());
    }

    int Top()
    {
        if (arr.empty())
        {   
            throw out_of_range("out of range");
        }

        return arr[0];
    }   

    int Size()
    {
        return arr.size();
    } 

    void Sort()
    {
        cout<<endl<<"Before  Heap Sort"<<endl;
        Print();
 
        for (int n = Size() - 1; n >= 0; n--)
        {
            swap(arr[0], arr[n]);
            HeapifyDown(0, n);
            Print();
        }

        cout<<endl<<"After Heap Sort"<<endl;
        Print();
        cout<<endl;    
    }  
};

int main(int argc, char **argv)
{
    MaxHeap mp;
/*
    cout<<"Pushing 3 2 15"<<endl;
    mp.Push(7);
    mp.Push(8);
    mp.Push(15);
       
    cout<<"Size is "<<mp.Size()<<endl;
    
    cout<<mp.Top()<<endl;
    mp.Pop();

    cout<<mp.Top()<<endl;
    mp.Pop();

    cout<<mp.Top()<<endl;

    cout<<"Pushing 5 4 45"<<endl;

    mp.Push(5);
    mp.Push(4);
    mp.Push(45);

    cout<<"Size is "<<mp.Size()<<endl;

    cout<<mp.Top()<<endl;
    mp.Pop();

    cout<<mp.Top()<<endl;
    mp.Pop(); 

    cout<<mp.Top()<<endl;
*/
    mp.Push(23);
    mp.Push(5);
    mp.Push(9);
    mp.Push(25);
    mp.Push(11);
    mp.Sort();
    return 0;
}
