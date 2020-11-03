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
        cout << node->data<<endl;
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

SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    SinglyLinkedListNode *node = head;

    if(position==0)
    {
       node = head->next;
       head=node;
    }
    else{
        if(head==NULL){
            return head;
        }

        else
        {       
        for(int i=1;i<position && node!=NULL;i++)
        {
            node=node->next;
        }
        node->next=node->next->next;
        }
}
return head;
}

int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();
    int llist_count;
    cin >> llist_count;
    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;
        
        llist->insert_node(llist_item);
    }

    int position;
    cin >> position;

    SinglyLinkedListNode* llist1 = deleteNode(llist->head, position);
    print_singly_linked_list(llist1);
    free_singly_linked_list(llist1);
}
