#include <iostream>
using namespace std;

struct Node{
    Node *prev;
    int data;
    Node *next;
};

class DoublyLL{
private:
    Node *head;
    int node_count=0;

public:
    DoublyLL(){
        head=nullptr;
    }

    void insert(int value, int pos){
        Node *t=new Node;
        t->data=value;

        if (pos==0){
            t->next=head;
            t->prev=nullptr;
            
            if (head){
                head->prev=t;
            }
            
            head=t;

            node_count++;
        }   
        
        else{
            Node *p=head;

            for (int i = 0; i < pos-1; i++){
                p=p->next;
            }
            
            t->next=p->next;
            t->prev=p;

            if (p->next){
                p->next->prev=t;
            }
            
            p->next=t;

            node_count++;
        }
    }

    void changeHead(int pos){
        Node *first=head;
        Node *second=head;

        Node *next1=head->next;
        
        for (int i = 0; i < pos-1; i++){
            second=second->next;
        }

        Node *prev2=second->prev;
        Node *next2=second->next;
        
        second->next=next1;
        second->prev=NULL;
        next1->prev=second;

        first->prev=prev2;
        prev2->next=first;
        first->next=next2;

        if (next2){
            next2->prev=first;
        }

        head=second;
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

    DoublyLL DLL;

    DLL.insert(1, 0);
    DLL.insert(2, 1);
    DLL.insert(3, 2);
    DLL.insert(4, 3);
    DLL.insert(5, 4);
    DLL.insert(6, 5);

    DLL.display();

    DLL.changeHead(3);

    DLL.display();

    return 0;
}