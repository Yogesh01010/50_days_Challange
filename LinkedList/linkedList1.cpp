#include<iostream>
using namespace std;

//linked list creation
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};


//Head pe koi nya node add krne ko function.
void insertAtHead(Node* &head, int d){
    
    // step1 create new node
    Node* temp = new Node(d);

    //step2 nye vale node ka pointer jo by default null hai usde hta k head ko point krva do.
    temp->next=head;

    //step3 head ko ab temp pe la do 
    head = temp;
}


//tail pe koi nya node add krne ko function.
void insertAtTail(Node* tail , int d){

    // step1 create new node
    Node* temp = new Node(d);
    // step2 
    tail -> next = temp;
    tail = temp;

}


// insert the data at given position.
void insertAtPosition(Node* &tail, Node* &head , int position,int d){

    //in case in sert at start
    if(position == 1){
        insertAtHead(head,d);
        return;
    }

    Node* temp =  head;
    int cnt =  1;
    while(cnt< position-1){
        temp = temp -> next;
        cnt++;
    }

    //in case insert at last
    if(temp -> next == NULL){
        insertAtTail(tail,d);
    }

    //create new node.
    Node* nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;

    temp->next = nodeToInsert;
    
}

//triverse or print a link list
void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main(){

    //  create a new node
    Node* node1 = new Node(10);
    /*cout << node1->data  <<endl;
    cout << node1->next <<endl;*/

    // point head to new node.
    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertAtHead(head,12);
    insertAtHead(head,15);
    insertAtTail(tail,22);
    print(head);

    insertAtPosition(tail,head,5,32);
    print(head);

    return 0;
}
