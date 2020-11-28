#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    stack<int> stk1,stk2;
    int Q;
    cin >> Q;
    while(Q--)
    {
        int type, x;
        cin >> type;
        if(type == 1)
        {
            cin >> x;
            stk1.push(x);
        }    
        else 
        {
           if(stk2.empty())
           {
               while(!stk1.empty())
               {
                   stk2.push(stk1.top());
                   stk1.pop();
               }   
            }    
           if(!stk2.empty())
           {
               if(type == 2) stk2.pop();
               if(type == 3) cout << stk2.top() << endl;
           }  
        }   
    }    
    return 0;
}
