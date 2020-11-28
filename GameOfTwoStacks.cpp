#include <bits/stdc++.h>
using namespace std;

int main(){ 
    int s;
    cin >> s;    
    for(int i = 0; i < s; i++)
    {
        int n,m,x;
        cin >> n >> m >> x;
        
        vector<int> a(n);
        for(int i = 0; i <n; i++)
        {
           cin >> a[i];
        }
        
        vector<int> b(m);
        for(int i =0; i <m; i++)
        {
           cin >> b[i];
        }
        
        int sum=0,count=0,i=0,j=0;        
        
        while(i<n && sum+a[i]<=x){    //considering only first stack and calculating count
            sum+=a[i];
            i++;
            count++;
        }       
       
        while(j<m)
        { //now adding one element of second stack at a time    
            sum+=b[j];             
            j++;

            while(sum>x && i>0) 
            {
                i--;
                sum-=a[i]; //if total is greater than x then remove a element from stack a 
            }

            if(sum<=x && i+j>count)
                count=i+j;
        }
        cout<<count<<endl;
    } 
}