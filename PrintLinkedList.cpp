#include <bits/stdc++.h>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;  //data
        SinglyLinkedListNode *next; //next pointer

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


void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

void printLinkedList(SinglyLinkedListNode* head) {

    while(head!=NULL)
    {
        cout<< head->data <<endl;
        head=head->next;
    }
}

int main()
{
    SinglyLinkedList* llist = new SinglyLinkedList();

    int n;
    cin >> n;
   
    for (int i = 0; i <n; i++) {
        int nodes;
        cin >> nodes;

        llist->insert_node(nodes);
    }
    printLinkedList(llist->head);  //fuction calling 

}