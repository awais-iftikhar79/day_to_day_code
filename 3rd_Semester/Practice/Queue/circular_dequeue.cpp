#include <iostream>
using namespace std;

class DeQueue
{
private:
    int size;
    int rear;
    int front;
    int *DQ;

public:
    DeQueue()
    {
        size = 5;
        rear = front = 0;
        DQ = new int[size];
    }
    DeQueue(int size)
    {
        this->size = size;
        rear = front = 0;
        DQ = new int[this->size];
    }

    void insert_at_front(int value);
    void insert_at_rear(int value);
    int delete_at_rear();
    int delete_at_front();
    bool is_empty();
    bool is_full();
    void dispaly();
};

bool DeQueue::is_full()
{
    return ((rear + 1) % size == front);
}

bool DeQueue::is_empty()
{
    return (rear == front);
}
void DeQueue::insert_at_rear(int value)
{
    if (is_full())
    {
        cout << "DeQueue is already Full !" << endl;
        return;
    }
    rear = (rear + 1) % size;
    DQ[rear] = value;
}

void DeQueue::insert_at_front(int value)
{
    if (is_full())
    {
        cout << "DeQueue is already Full !" << endl;
        return;
    }
    front = (front - 1 + size) % size;
    DQ[front] = value;
}

int DeQueue::delete_at_front()
{
    int x = -1;
    if (is_empty())
    {
        cout << "DeQueue is Empty !" << endl;
        return x;
    }
    front = (front + 1) % size;
    x = DQ[front];
    return x;
}

int DeQueue::delete_at_rear()
{
    int x = -1;
    if (is_empty())
    {
        cout << "DeQueue is Empty !" << endl;
        return x;
    }
    rear = (rear - 1 + size) % size;
    x = DQ[rear];
    return x;
}

void DeQueue::dispaly()
{
    if (is_empty())
    {
        cout << "DeQueue is Empty !" << endl;
        return;
    }
    int i = front + 1;
    while (i != (rear + 1) % size)
    {
        cout << DQ[i] << " ";
        i = (i + 1) % size;
    }
    cout << endl;
}
int main()
{
    DeQueue dq;

    dq.insert_at_rear(1);
    dq.insert_at_rear(3);
    dq.insert_at_front(5);

    dq.dispaly();

    return 0;
}