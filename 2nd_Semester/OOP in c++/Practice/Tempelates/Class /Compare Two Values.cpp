#include <iostream>
using namespace std;
template <class T>
class Compare
{
private:
    T num1, num2;

public:
    Compare() {};
    Compare(T a, T b) : num1(a), num2(b) {}
    bool is_equal()
    {
        return (num1 == num2);
    }
};
int main()
{
    Compare<int> c1(3, 3);
    cout << boolalpha << c1.is_equal() << endl;
    cout << "-------------" << endl;
    Compare<double> c2(3.5, 6.3);
    cout << boolalpha << c2.is_equal() << endl;
    cout << "-------------" << endl;
    Compare<char> c3('z', 'z');
    cout << boolalpha << c3.is_equal() << endl;
    cout << "-------------" << endl;
    Compare<string> c4("Awais", "Abid");
    cout << boolalpha << c4.is_equal() << endl;

    return 0;
}