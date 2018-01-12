/*
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.

*/

class Solution {
public:
    string addStrings(string num1, string num2) {
        
        string result;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        
        for (; i >= 0 || j >= 0; ) 
        {
            if (i >= 0) 
                carry += num1[i--] - '0';
            
            if (j >= 0) 
                carry += num2[j--] - '0';
            
            
            result = to_string(carry % 10) + result;
            carry /= 10;
            
        }
        
        if (carry == 1)
            result = to_string(1) + result;
        
        return result;
    }
};
