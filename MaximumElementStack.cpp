#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,qtype,x;
    int cmax=INT_MIN;
    stack <pair<int,int>> stk;
    cin>>n;
    while(n--)
    {
        cin>>qtype;

        if(qtype == 1) //if 1 then it's mean inserting in the stack
        {
            cin>>x;
            cmax=max(x,cmax);
            stk.push(make_pair(x,cmax));
        }

        else if(qtype==2) //if 2 then it's mean deleting from the stack
        {
            stk.pop();
                if(stk.empty())
                {
                    cmax = INT_MIN;
                }
                else
                {
                   cmax = stk.top().second;
                }     
        }

        else // if 3 means printing the stack
        {
            cout<<cmax<<endl;
        }
        
    }
}