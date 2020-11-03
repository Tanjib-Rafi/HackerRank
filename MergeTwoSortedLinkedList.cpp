#include <bits/stdc++.h>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }
            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        cout << node->data;
        node = node->next;
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;
        free(temp);
    }
}

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    SinglyLinkedListNode *one =head1;
    SinglyLinkedListNode *two =head2;
    SinglyLinkedListNode *merge = NULL;

    if(head1==NULL){
      return head2;
    }
    if(head2==NULL){
      return head1;
    }
if(one && two)
{
      if(one->data <=two->data)
      {
          merge = one;
        one=merge->next;
      }
      else
      {
          merge = two;
          two=merge->next;
      }
}
     SinglyLinkedListNode *newMerge=NULL;
    newMerge=merge;
      while(one!=NULL && two!=NULL)
      {
          if(one->data<=two->data)
          {
              merge->next=one;
              merge=one;
              one=merge->next;
          }
          else
          {
              merge->next=two;
              merge=two;
              two=merge->next;
          }
      }

      if(one==NULL){merge->next=two;}
      if(two==NULL){merge->next=one;}
      return newMerge;
}

int main()
{
    int tests;
    cin >> tests;
   
    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist1 = new SinglyLinkedList();
        int llist1_count;
        cin >> llist1_count;   
        for (int i = 0; i < llist1_count; i++) {
            int llist1_item;
            cin >> llist1_item;
            
            llist1->insert_node(llist1_item);
        }
      
      	SinglyLinkedList* llist2 = new SinglyLinkedList();
        int llist2_count;
        cin >> llist2_count;
        for (int i = 0; i < llist2_count; i++) {
            int llist2_item;
            cin >> llist2_item;
            
            llist2->insert_node(llist2_item);
        }

        SinglyLinkedListNode* llist3 = mergeLists(llist1->head, llist2->head);
        print_singly_linked_list(llist3);  
        free_singly_linked_list(llist3);
    }
}
