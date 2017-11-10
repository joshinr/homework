#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
    public:
        stack<unsigned long> for_push, for_pop;   

        void push(unsigned long num) 
        {
            for_push.push(num);
        }

        unsigned int pop() 
        {
            unsigned int num = front();
            for_pop.pop();
            return num;
        }
    
        unsigned int front()
        {
            if (for_pop.empty())
            {
                unsigned int count = for_push.size();
                for (unsigned int i = 0; i < count; ++i)
                {
                    for_pop.push(for_push.top());
                    for_push.pop();
                }
            }
           return for_pop.top();
        }
    
        
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
