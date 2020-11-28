#include <bits/stdc++.h>
using namespace std;

string isBalanced(string s) {
    
    stack <char> stk;
    
    for (int i=0; i<s.size(); i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
        {
            stk.push(s[i]);
        }
        else if(!stk.empty() && 
                (
                 s[i]==')' && stk.top()=='(' ||
                 s[i]=='}' && stk.top()=='{' ||
                 s[i]==']' && stk.top()=='['
                 )
                 )
                {
                    stk.pop();
                }
        else
            return "NO";
    }
    
    if(stk.empty())
    {
        return "YES";
    }
    else
        return "NO";

}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) 
    {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        cout << result << "\n";
    }

}
