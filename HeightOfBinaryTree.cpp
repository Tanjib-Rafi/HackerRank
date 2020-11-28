#include <bits/stdc++.h>
using namespace std;

class Node {
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

    int height(Node* root) {
        int i= 0;
    Node* n = root;
    while( n && (n->left != NULL || n->right!= NULL) )
    {
      if (n->right != NULL)
      {
          n = n->right;
          i++;
          continue;
      }

      if (n->left != NULL)
      {
          n = n->left;
          i++;
          continue;
      }
    }
    return i;
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
    int height = myTree.height(root);  
  	cout << height;
    return 0;
}
