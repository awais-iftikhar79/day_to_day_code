#include <iostream>
#include <string>
using namespace std;
class password_mang
{
private:
    string password;
    string encrypt_pass()
    {
        string encrypt = password;
        for (int i = 0; i < encrypt.length(); i++)
        {
            encrypt[i] = encrypt[i] + 1;
        }
        return encrypt;
    }

public:
    void set_password(string pass)
    {
        password = pass;
    }
    string get_encrypted()
    {
        return encrypt_pass();
    }
};
int main()
{
    password_mang p;
    string password;
    cout << "Enter your password" << endl;
    getline(cin, password);
    p.set_password(password);
    cout << "Encrypted password is : " << p.get_encrypted() << endl;

    return 0;
}