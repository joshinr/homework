/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

void palindromeSubString(const string &str)
{
    int length = str.length();
    int table[length][length];
    memset(table, 0, length);
    
    int start = 0;
    int maxLength = 1;
    
    for(int i=0; i<length; ++i)
    {
        table[i][i] = 1;
    }
    
    for(int i=0; i<length-1; ++i)
    {
        if (str[i] == str[i+1])
        {
            start = i;
            maxLength = 2;
            table[i][i+1] = 1;
        }
    }
    
    for(int i=3; i<=length; ++i)
    {
        for(int j=0; j<length - i + 1; ++j)
        {
            int k = i + j - 1;
            
            if (str[j] == str[k] && table[j+1][k-1] == 1)
            {
                table[j][k] = 1;
                if (k > maxLength)
                {
                    maxLength = i;
                    start = j;
                }
            }
        }
    }
    
    cout<<endl<<"start "<<start<<" length "<<maxLength;
    cout<<endl<<str.substr(start, maxLength);
    
}
int main()
{
    
    palindromeSubString("forgeeksskeegfor");

    return 0;
}
