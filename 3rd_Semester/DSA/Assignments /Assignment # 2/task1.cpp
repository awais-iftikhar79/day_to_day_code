#include <iostream>
using namespace std;

int node_count=0;

struct Node{
    int data;
    Node *next;
    int pos;
};

class LinkedList{
private:
    Node *head;

public:
    LinkedList(){
        head=nullptr;
    }

    void insertEnd(int value){
        Node *t=new Node;
        t->data=value;

        if (head==nullptr){
            t->next=nullptr;
            head=t;
        }
        
        else{
            Node *p=head;

            while (p->next!=nullptr){
                p=p->next;
            }
            
            p->next=t;
            t->next=nullptr;
        }

        t->pos=++node_count;
    }

    void insertStart(int value){
        Node *t=new Node;
        t->data=value;
        t->next=head;
        head=t;

        t->pos=++node_count;
    }

    void createLoop(int pos){
        Node *p=head;
        Node *q=head;

        while (p->next!=nullptr){
            p=p->next;
        }

        for (int i = 0; i < pos-1; i++){
            q=q->next;
        }
        
        p->next=q;
    }

    int checkLoop(){
        Node *slow=head;
        Node *fast=head;

        Node *p=head;

        int x;

        for (int i = 0; i < node_count-1; i++){
            p=p->next;
        }

        while (fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;

            if (slow==fast){
                cout<<"There is a loop at position "<<p->next->pos<<" in linked list!"<<endl;

                x=p->next->data;

                cout<<"Loop removed from Node "<<p->pos<<" > Node "<<p->next->pos<<endl;

                p->next=nullptr;
                return x;
            }
        }

        cout<<"There is no loop in linked list!"<<endl;

    }

    void display(){
        Node *p=head;

        while (p!=nullptr){
            cout<<p->data<<"->";
            p=p->next;
        }
        
        cout<<"NULL"<<endl;
    }
};

int main(){
    LinkedList LL;

    LL.insertEnd(11);
    LL.insertEnd(3);
    LL.insertEnd(8);
    LL.insertEnd(2);
    LL.insertEnd(1);

    LL.display();

    // Creating loop at index 2

    LL.createLoop(2);

    cout<<"Value inside the node where loop is present: "<<LL.checkLoop()<<endl;

    LL.checkLoop();

    return 0;
}