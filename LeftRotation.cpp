#include<bits/stdc++.h>
using namespace std;

vector<int> rotateLeft(int d, vector<int> arr)
{
    
    int size = arr.size();
    //int temp = arr[0];
    for( int k=0; k<d; k++)
    {
        int temp = arr[0];
    for(int i=0; i<size-1; i++)
    {        
            arr[i]=arr[i+1];  
    }   
        arr[arr.size()-1]=temp;
        
    }
    

     return arr;
    
}
int main()
{
    int n,d;
    cin>>n>>d;

    vector<int> arr(n);

    for (int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    vector<int> result = rotateLeft(d,arr);

    for(int i = 0; i<result.size(); i++)
    {
        cout<<result[i]<< " ";
    }

}