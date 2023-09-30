#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    //constructure
    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node(){
        int val = this->data;
        if(next!=NULL){
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data"<< val <<endl;
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

//code for get the length of the linklist
int getLength(Node* &head){

    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

// ineret at head in a doublyy linkedlist.
void inseriAtHead(Node* &head, int d){
    //if empty list
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
    }else{
        Node* temp = new Node(d);

       temp->next = head;
       head -> prev = temp;
       head = temp ;
    }

}

// ineret at tail in a doublyy linkedlist.

void insertAtTail(Node* &tail,int d){

    if(tail == NULL){
        Node* temp = new Node(d);
        tail = temp;
    }else{
        Node* temp = new Node(d);//creation of new node

        tail->next = temp; //tail k next ko new node k equal kr do 
        temp ->prev = tail; //nye node k previous ko tail k equal ke  do 
        tail = temp; //tail ko nye vale node pe kr  do .
    }
}


void insertAtPosition(Node* &tail,Node*&head,int position , int d){
    //insert at start
    if(position ==1){
        inseriAtHead(head,d);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }

    // inserting at last position
    if(temp->next == NULL){
        insertAtTail(tail,d);
        return;
    }

    // creating nodeToInsert
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev=temp;
}


void deleteNode(int position,Node* &head){
    //deleting first or starting node
    if(position == 1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp->next;
        temp -> next = NULL;
        delete temp;

    }else{
        // deleting any middle or last node
        Node * current = head;
        Node * prev = NULL;//delete krne se phle uspe lge pointer ko hta do

        int cnt = 1;
        while(cnt < position){
            prev = current;
            current = current -> next;
            cnt++;
        }

        current -> prev = NULL;
        prev -> next = current->next;
        current->next = NULL;
        delete current;
    }
}

int main() {
    Node* node1 =  new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    cout << getLength(head)<<endl;

    inseriAtHead(head,11);
    inseriAtHead(head,12);
    inseriAtHead(head,13);
    print(head);

    insertAtTail(tail,25);
    print(head);

    insertAtPosition(tail,head,6,100);
    print(head);

    deleteNode(1,head);
    print(head);

    return 0;
}



/*
//insert at head in doubely linkedlist
step1->create a new node;
step2->nye node ka -> next = head krdo
step3-> head ka -> previous = nyanode krdo
step4-> nya node = head krdo;
*/


/*
//insert at head in doubely linkedlist
step1->create a new node;
step2->tail k next ko new node k equal kr do 
step3-> nye node k previous ko tail k equal ke  do 
step4-> tail ko nye vale node pe kr  do
*/