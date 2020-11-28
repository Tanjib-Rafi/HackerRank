#include <bits/stdc++.h>
using namespace std;

class Node 
{
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
  	
  	void preOrder(Node *root) 
    {	
      	if( root == NULL )
          	return;
      
      	cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
    }



    Node * insert(Node * root, int data) 
    {  
        Node* newnode = new Node(data);
        newnode->data = data;
       
     if (root == NULL) 
     {
      return newnode; // if null we have to return the value creating new node
     }

    Node* current_node = root;
    
    while(current_node!= NULL)
    {
        if(current_node->data > data)
        {
            if(current_node->left == NULL)//if no value in left than insert a newnode
            {
            current_node->left = newnode;
            break;
            }
            else
                current_node = current_node->left; // if value available iterate throught the left and find the last
        }
        
        else
        {
            if(current_node->right == NULL)
            {
                current_node->right = newnode;
                break;
            }
            else
            current_node =current_node->right;
        }
    }
              
   return root;
}
};

int main() 
{
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    cin >> t;

    while(t-- > 0) {
        cin >> data;
        root = myTree.insert(root, data);
    }
  	
    myTree.preOrder(root);
  
    return 0;
}
