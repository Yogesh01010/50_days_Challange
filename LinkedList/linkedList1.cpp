//linked list creation
//insert at head
//insert at tail
//insert at any position
//Deletion by (value) or by (position)

//triverse or print linked list.

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

    // distructor
    ~Node(){
        int value = this -> data;
        //memory free
        if(this->next !=NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free for node with data"<< value << endl;
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


void deleteNode(int position,Node* &head,Node*tail){
    //deleting first or starting node
    if(position == 1){
        Node* temp = head;
        head = head-> next;
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

        prev -> next = current -> next;
        current -> next = NULL;//delete krne se phle uspe lge pointer ko hta do
        tail = prev;
        delete current;
    }
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

    deleteNode(2,head,tail);
    print(head);

    return 0;
}




/*for deletion singly linkedlist
 
 delete first node (we store first node in temp)
 1->  head = head->next;
 2-> temp -> next = NULL;
 3-> delete temp.


 delete last node . 
 second last node ko prevesious kr denge and last node ko temp
 step 1-> find privous
 step 2-> previous -> next = NULL;
 step 3-> tail = previous;
 step 4-> delete temp;

 delete from the given position 
 step 1-> find previous and current (current delet hone vale node ko point krega or previous uske phle vale node ko)
 step 2-> previous -> next = current -> next;
 step 3-> current -> next =  NULL;
 step 4-> delete current ;
*/
