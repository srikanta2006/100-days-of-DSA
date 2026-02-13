#include<iostream>
using namespace std;

class Node{
public :
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;

public:
    List(){
        head = NULL;
        tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val); //dynamic object
        if(head == NULL){ // linked list empty
            head = tail = newNode;
            return;
        }
        else{ //Not empty
            newNode->next =head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head = tail = newNode;
            return;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front(){
        if(head==NULL){
            cout << "List is empty"<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next =NULL;
        delete temp;
    }

    void pop_back(){
        if(head==NULL){
            cout << "List is empty"<<endl;
            return;
        }
        Node* temp=head;
        while(temp->next!=tail){
            temp=temp->next; 
        }
        temp->next = NULL;
        delete tail;
        tail =temp;
    }

    void insert(int val, int pos){
        if(pos<0){
            return;
        }

        if(pos == 0){
            push_front(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;
        for(int i=0; i<pos-1; i++){
            temp=temp->next;
        }
        newNode = temp->next;
        temp->next = newNode;
    }

    bool search(int val){
        Node* temp = head;
        while(temp->next !=NULL){
            if(temp->data == val){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }
    

    void display(){
        Node* temp = head;
        while(temp !=NULL){
            cout<<temp->data << "->";
            temp=temp->next;
        }
        cout << "NULL"<<endl;
    }
};

int main(){
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(4);
    ll.display();
    ll.pop_front();
    ll.pop_back();
    ll.display();

    return 0;
}