#include<bits/stdc++.h>
using namespace std;

vector<int> dynamicArray (int n, vector<vector<int>> queries)
{   
    vector<vector<int>> seqList(n);
    int lastAnswer = 0;
    int size = queries.size();
    vector <int> ans;


    for(int i = 0; i< size; i++)
    {
        int seq = (queries[i][1] ^ lastAnswer) % n; //for both conditon so we are declareing these outside of if-else

        if(queries[i][0]==1) //first condition 
        {    
            seqList[seq].push_back(queries[i][2]);
        }

        else if(queries[i][0]==2) //second conditon
        {
            int ind = queries[i][2]%(seqList[seq].size());
            lastAnswer = seqList[seq][ind];
            ans.push_back(lastAnswer);
        }
    }

return ans;
}

int main()
{
    int n,q;

    cin>>n>>q;

    vector<vector<int>> queries(q); //vector of size q
    
    for(int i=0; i<q; i++)
    {
        queries[i].resize(3);
        for(int j = 0 ; j<3 ; j++)
        {
            cin>>queries[i][j];  //taking input 
        }
    }

    vector<int> result = dynamicArray(n,queries);
    
        for(int i=0; i<result.size(); i++)
        {
            cout<<result[i]<<" "; //printing vector
        }


}