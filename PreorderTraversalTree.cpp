#include <bits/stdc++.h>
using namespace std;

//      1
//       \
//        2
//         \
//          5
//         /  \
//        3    6
//         \
//          4

class Node 
{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d)
         {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution 
{
    public:
  		Node* insert(Node* root, int data)
           {
            if(root == NULL) 
            {
                return new Node(data);
            } 
            else 
            {
                Node* cur;
                if(data <= root->data) 
                {
                    cur = insert(root->left, data);
                    root->left = cur;
                } 
                else
                 {
                    cur = insert(root->right, data);
                    root->right = cur;
                 }
               return root;
           }
        }

void preOrder(Node *root) 
    {
        if(root==NULL) //checking if the root is exit or not
            return;
        
        stack <Node*> stk; //creating a pointer type stack
        
        stk.push(root); //pushing the root in the stack

        while(!stk.empty()) //the loop will continuing until the stack becomes empty
        {
            Node* current_node = stk.top(); //top value of the stack is root

            cout << current_node->data << " "; //printing the root 

            stk.pop(); //removing the root from the stack

            if (current_node->right != NULL)  //first right because stack follows LIFO 
            {
                stk.push(current_node->right); //pushing in stack
            }
              if (current_node->left != NULL) //then left 
            {
                stk.push(current_node->left); //pushing in stack
            }
        }
    }

}; 

int main() 
{
    Solution myTree; //creating a class object

    Node* root = NULL;
    
    int t;
    int data;
    cin >> t; //number of nodes

    while(t-- ) 
    {
        cin >> data;
        root = myTree.insert(root, data);
    }
	myTree.preOrder(root);
}
