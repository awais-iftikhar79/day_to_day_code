#include <iostream>
using namespace std;

class Person{
public:
    string name;
    string address;
    long long int ph_num;
};

struct Node{
    Person info;
    Node *next;
};

class LinkedList{
private:
    Node *head;

public:
    LinkedList(){
        head=nullptr;
    }

    void sortedInsert(string name, string address, long long int ph_num){
        Node *p=head;
        Node *q=nullptr;

        Node *t=new Node;
        t->info.name=name;
        t->info.address=address;
        t->info.ph_num=ph_num;
        t->next=nullptr;

        if (head==NULL){
            head=t;
        }
        
        else{
            while (p && p->info.name<name){
                q=p;
                p=p->next;
            }

            if (p==head){
                t->next=head;
                head=t;
            }
            
            else{
                t->next=q->next;
                q->next=t;
            }
        }
    }

    void find(string name){
        Node *p=head;

        while (p!=nullptr){
            if (p->info.name==name){
                cout<<"Person Record for "<<name<<":"<<endl;
                cout<<"Address: "<<p->info.address<<endl;
                cout<<"Phone Number: "<<p->info.ph_num<<endl;

                return;
            }
            
            p=p->next;
        }
    }

    void display(){
        Node *p=head;

        cout<<">>> ADDRESS BOOK <<<"<<endl;
        while (p!=nullptr){
            cout<<p->info.name<<" -> ";
            p=p->next;
        }
        
        cout<<"NULL"<<endl;
    }
};

int main(){
    LinkedList LL;

    int num_people;

    cout<<"Enter the amount of people you want to enter data for: ";
    cin>>num_people;
    cin.ignore();

    string name[num_people];
    string address[num_people];
    long long int ph_num[num_people];

    for (int i = 0; i < num_people; i++){
        cout<<"Enter name of person "<<i+1<<": ";
        getline(cin, name[i]);

        cout<<"Enter address of person "<<i+1<<": ";
        getline(cin, address[i]);

        cout<<"Enter phone number of person "<<i+1<<": ";
        cin>>ph_num[i];
        cin.ignore();

        LL.sortedInsert(name[i], address[i], ph_num[i]);
    }

    LL.display();

    string n;

    cout<<"Enter a person's who you want to see information for: ";
    getline(cin, n);

    LL.find(n);
    
    return 0;
}