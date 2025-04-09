#include <iostream>
using namespace std;
template <class T>
class Pair
{
private:
    T first, second;

public:
    Pair(T a, T b) : first(a), second(b) {}
    void display()
    {
        cout << "First : " << first << endl;
        cout << "Second : " << second << endl;
    }
    void swap()
    {
        T temp;
        temp = first;
        first = second;
        second = temp;
    }
};
int main()
{
    Pair<int> p(3, 6);
    p.display();
    p.swap();  
    return 0;
}