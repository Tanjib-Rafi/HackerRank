#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;//here greater is used for sorting the elements in assending order 
priority_queue<int, vector<int>, greater<int> > pqRemove;

void add(){
    int n;
    cin>>n;
    pq.push(n);
}

void remove()
{
    int n;
    cin>>n;
    pqRemove.push(n);
    
}

void printMin(){
    
    while(!pqRemove.empty() && pqRemove.top() == pq.top()){ //checking if both have same value or not .If not then print the top of pq
        pq.pop();
        pqRemove.pop();
    }
    cout<<pq.top()<<endl;
}
    
int main() {

    int q;
    cin>>q;
    while(q--){
        int command;
        cin>>command;
        if(command == 1)
            add();
        else if(command == 2)
            remove();
        else if(command == 3)
            printMin();
    }
    return 0;
}