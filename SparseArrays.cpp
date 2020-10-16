#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,count;

    cin>>n;
    string s1[1000],s2[1000];


    for(int i=0; i<n; i++)
    {
       cin>>s1[i];
    }
        cin>>m;
            for(int j=0; j<m; j++){
                cin>>s2[j];
                int count = 0;
                for(int i=0; i<n; i++)
                {
                    
            if(s2[j]==s1[i])
            count++;
        }
            
        cout<<count<<endl;
    }

}



