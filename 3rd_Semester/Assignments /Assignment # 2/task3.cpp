#include <iostream>
using namespace std;

int node_count=0;

struct Node{
    Node *prev;
    int data;
    Node *next;
};

class DoublyLL{
private:
    Node *head;

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

    // Function for swapping k-th nodes from each end

    void swap_nodes(int k){
        Node *p=head;
        Node *q;

        if (k<1 || k>node_count){
            cout<<"Value of k is out of range!"<<endl;
        }
        
        Node *first=head;
        Node *second=head;

        for (int i = 1; i < k; i++){
            first=first->next;
        }
        
        for (int i = 1; i < node_count-k+1; i++){
            second=second->next;
        }
        
        // Handling adjacent nodes

        // 1. First before second
        if (first->next==second){
            Node *prev1=first->prev;
            Node *next2=second->next;

            if (prev1){
                prev1->next=second;
            }
            
            second->prev=prev1;
            second->next=first;
            first->prev=second;
            first->next=next2;

            if (next2){
                next2->prev=first;
            }
            
            if (head==first){
                head=second;
            }
        }
        
        // 2. Second before first
        if (second->next==first){
            Node *prev2=second->prev;
            Node *next1=first->next;

            if (prev2){
                prev2->next=first;
            }
            
            first->prev=prev2;
            first->next=second;
            second->prev=first;
            second->next=next1;

            if (next1){
                next1->prev=second;
            }
            
            if (second==head){
                head=first;
            }
        }
        
        // Non-adjacent nodes case

        else{
            Node *prev1=first->prev;
            Node *next1=first->next;
            Node *prev2=second->prev;
            Node *next2=second->next;

            second->next=next1;
            next1->prev=second;
            second->prev=prev1;

            if (prev1){
                prev1->next=second;
            }

            first->prev=prev2;
            prev2->next=first;
            first->next=next2;
            
            if (next2){
                next2->prev=first;
            }
                       

            if (first==head){
                head=second;
            }
            
            else if (second==head){
                head=first;
            }
        }
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

    DLL.swap_nodes(1);

    DLL.display();

    return 0;
}