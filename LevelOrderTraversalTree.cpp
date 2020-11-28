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

    void levelOrder(Node * root)
     {
        
        if(root == NULL) 
        return;
        
        queue<Node*> queue;
        queue.push(root);
        
        while(!queue.empty())  
        {
         Node* current_node = queue.front();
         cout<<current_node->data<<" ";
         queue.pop();
         
         if(current_node->left != NULL)
         {
             queue.push(current_node->left);
         }
          if(current_node->right != NULL)
         {
             queue.push(current_node->right);
         }
    }
    }

};

int main() 
{
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;
    cin >> t;

    while(t-- > 0) 
    {
        cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.levelOrder(root);
    return 0;
}
