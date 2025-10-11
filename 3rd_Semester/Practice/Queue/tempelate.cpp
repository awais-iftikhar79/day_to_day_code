#include <iostream>
using namespace std;

template <class T> // 🔹 Template declaration
class Queue
{
private:
    int size;
    int rear;
    int front;
    T *Q; // 🔹 Now holds generic type elements (T)

public:
    Queue()
    {
        size = 10;
        front = 0;
        rear = 0;
        Q = new T[size];
    }

    Queue(int size)
    {
        this->size = size;
        front = 0;
        rear = 0;
        Q = new T[this->size];
    }

    void enqueue(T value);
    T dequeue();
    void display();
    bool is_full();
    bool is_empty();
};

template <class T>
bool Queue<T>::is_full()
{
    return ((rear + 1) % size == front);
}

template <class T>
bool Queue<T>::is_empty()
{
    return (front == rear);
}

template <class T>
void Queue<T>::enqueue(T value)
{
    if (is_full())
    {
        cout << "Queue is already full!" << endl;
        return;
    }
    else
    {
        rear = (rear + 1) % size;
        Q[rear] = value;
    }
}

template <class T>
T Queue<T>::dequeue()
{
    T x = T(); // 🔹 Initialize with default value of T

    if (is_empty())
    {
        cout << "Queue is already empty!" << endl;
        return x;
    }
    else
    {
        front = (front + 1) % size;
        x = Q[front];
    }
    return x;
}

template <class T>
void Queue<T>::display()
{
    if (is_empty())
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    int i = (front + 1) % size;
    do
    {
        cout << Q[i] << " ";
        i = (i + 1) % size;
    } while (i != (rear + 1) % size);
    cout << endl;
}

int main()
{
    // 🔹 Queue for integers
    Queue<int> q1(6);

    q1.enqueue(5);
    q1.enqueue(10);
    q1.enqueue(15);
    q1.enqueue(20);
    q1.enqueue(25);
    q1.display();

    q1.dequeue();
    q1.display();

    cout << "Is empty? " << q1.is_empty() << endl;

    // 🔹 Queue for strings
    Queue<string> q2(4);
    q2.enqueue("Awais");
    q2.enqueue("Iftikhar");
   
    q2.display();

    q2.dequeue();
    q2.display();

    return 0;
}
