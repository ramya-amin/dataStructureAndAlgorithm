#include<iostream>

using namespace std;

class node{
    int data;
    node* next;

    public:
    node(){
        data=0;
        next=NULL;
    }
    node(int val){
        this->data=val;
        this->next=NULL;
    }
};

class myList{
    node* head;
    node* next;

    public:
    myList(){
        head=NULL;
        next=NULL;
    }

    void addToHead(int val){
        node* temp;
        temp->data = val;
        temp->next = head;
        head = temp;
    }
    void printList(){
        node* temp;
        temp = head;

        while(temp){
            cout<<temp->data<<endl;
            temp = temp->next;
        }
        
    }
};

int main(){
    myList l1 = new myList();

    l1.addToHead(2);
    l1.addToHead(10);

    l1.printList();

    return 0;

}

