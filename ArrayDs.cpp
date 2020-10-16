#include<bits/stdc++.h>
using namespace std;

vector<int> reverseArray (vector<int> a)
{
    vector<int> b; //we will store the result here

    int sizez = a.size(); //size of the vector

    for(int i=sizez-1; i>=0; i--)
    {
        b.push_back(a[i]);
    }

    return b;
}


int main()
{
    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0; i<n; i++)
    {
       cin>>a[i];
    }

    vector<int> result = reverseArray(a);

    for(int i=0; i<result.size(); i++)
    {
        cout<<result[i]<<" ";
    }

}