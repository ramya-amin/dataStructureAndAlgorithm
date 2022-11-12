#include<iostream>

using namespace std;

class node{
public:
    int data;
    node* next;

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
    int size;

    public:
    myList(){
        head=NULL;
        size=0;
    }

    //get the data in the given index number 
    int get(int index){

        //if the index is out of bound then return -1 ; if head is NULL then also -1 
        //else we have to traverse till index-1; so that when its index, loop exits and we can return
        //currNode->data 

        if(index >=size || index < 0 || head == NULL) return -1;
        else
        {
            node* currNode = head;
            for(int i=0;i<index; i++)
                currNode = currNode -> next;
            return currNode->data;
        }


    }

    void addToHead(int val){
        // node* temp=new node(val);
        // temp->next = head;
        // head = temp;
        // size++;
        addAtIndex( 0 , val);
    }

    void addAtTail(int val){
        // node* temp = new node(val);
        // node* traverse = new node();
        // traverse = head;

        // while(traverse->next){
        //     traverse = traverse->next ;
        // }
        // traverse->next = temp;

        // size++;

        addAtIndex(size , val);
    }

    void printList(){
        node* temp;
        temp = head;

        cout<<"\nLinked list elements : ";
        while(temp){
            cout<<temp->data<<'\t';
            temp = temp->next;
        }      
        cout<<"\n Size :"<<size;  
    }

    void addAtIndex(int index, int val) {
        node* new_node = new node(val);

        if(index > size || index < 0) return;

        else if(index == 0){
            //add to head 
            new_node->next = head;
            head = new_node;

        }
        else{
            // middle of the linkedList at x index 
            node* traverse = new node();
            traverse = head;
            int currIndex=0;
            while(traverse){
                if(currIndex == (index - 1)){
                    new_node->next = traverse->next;
                    traverse->next = new_node;
                    size++;

                    return;
                }
                traverse = traverse->next;
                currIndex++;

            }

            
        }
        size++;
    }
        void deleteAtIndex(int index) {

        node* temp = head;
        if(index >= size || index < 0 ) return;
        else{
        for(int i=0; i<index-1 ; i++)
            temp = temp->next;

        node* nextNode=temp->next->next;
        delete temp->next;
        temp->next = nextNode;
        }
        size--;
        
    }

};

int main(){
    myList* l1 = new myList();

    l1->addToHead(1);
    //l1->addToHead(10);
      //  l1->addToHead(11);

    l1->addAtTail(3);
    //l1->printList();
    l1->addAtIndex(1,2);
        //l1->printList();
    cout<<endl<<l1->get(1);
    l1->deleteAtIndex(1);
    //l1->deleteAtIndex(3);
    cout<<endl<<l1->get(1);


    //cout<<'\n'<<"Index : ";
    //cout<<l1->get(1)<<endl;
    l1->printList();

    return 0;

}

