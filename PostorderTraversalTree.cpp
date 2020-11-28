#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
    void postOrder(Node *root) 
    {
        if(root==NULL) 
        return;

        stack <Node*> stk; 
        stk.push(root);
        stack<int> res;

        while(!stk.empty())
        {
           Node* current_node = stk.top();       
           stk.pop(); 
           res.push(current_node->data);

           if (current_node->left != NULL) 
            {
                stk.push(current_node->left); 
            }   
                 if (current_node->right != NULL)
            {
                stk.push(current_node->right);
            }     
        }
        
        while(!res.empty())
        {
            cout<<res.top()<<" ";
            res.pop();
        }
        
    }
};

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    cin >> t;

    while(t--) {
        cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.postOrder(root);
}
