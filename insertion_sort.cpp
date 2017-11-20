// Example program
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

void insertion_sort(vector<int> &arr)
{
    int n = arr.size();
    
    for (int i=1; i<n; ++i)
    {
        int j = i;
        
        while(j > 0 && arr[j] < arr[j-1])
        {
            int tmp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = tmp;
            --j;
        }
    }
}

int main()
{
    vector<int> arr = {9, 8, 5, 3, 4, 2, 1};
    for (auto &n : arr)
    {
        cout <<n << " ";
    }
    cout <<endl;
    
    insertion_sort(arr);
    
    for (auto &n : arr)
    {
        cout <<n << " ";
    }
    cout <<endl;
    
  return 0;
}

/*
•	Worst case Θ(n^2).
•	Best case: Θ(n).
•	Average case for a random array: Θ(n^2).
•	"Almost sorted" caseΘ(n).
*/
