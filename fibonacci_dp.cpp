// Example program
#include <iostream>
#include <string>
#include <map>

using namespace std;

int fib_recursion(int n)
{
    if (n==0)
    {
        return 0;
    }
    
    if (n==1)
    {
        return 1;
    }
    
    return fib_recursion(n-1) + fib_recursion(n-2);
}

int fib_dp(int n)
{
     map<int, int> val;
     
     val[0] = 0;
     val[1] = 1;
     
     for (int i=2; i<=n; ++i)
     {
         val[i] = val[i-1] + val[i-2];
     }
     
     return val[n];
}

int main()
{
  std::cout <<fib_recursion(8)<<endl;
  std::cout <<fib_dp(8)<<endl;
  return 0;
}
