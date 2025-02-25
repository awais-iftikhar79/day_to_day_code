#include <iostream>
#include <string>
using namespace std;

class ClassB;

class ClassA
{
private:
    int numA;
    friend void add(ClassA, ClassB);

public:
    ClassA(int n)
    {
        numA = n;
    }
    void display()
    {
        cout << "Number of 1st Class is : " << numA << endl;
    }
};

class ClassB
{
private:
    int numB;
    friend void add(ClassA, ClassB);

public:
    ClassB(int n)
    {
        numB = n;
    }
    void display()
    {
        cout << "Number of 2nd Class is : " << numB << endl;
    }
};
void add(ClassA objA, ClassB objB)
{
    int sum = objA.numA + objB.numB;
    cout << "The sum of two numbers from different class is : " << sum << endl;
}

int main()
{
    ClassA a(4);
    a.display();
    ClassB b(6);
    b.display();
    add(a, b);

    return 0;
}