#include<iostream>
using namespace std;
class marks{
    private:
    int marks[5];
    public:
    void set_marks(){
        cout<<"Enter marks of student"<<endl;
        for (int i = 0; i < 5; i++)
        {
            cout<<"Subject "<<i+1<<endl;
            cin>>marks[i];
        }  
    }
    int cal_total(){
        int total=0;
        for (int i = 0; i < 5; i++)
        {
            total += marks[i];
        }
        return total;
    }
};
int main(){
    marks stu;
    stu.set_marks();
    int total=stu.cal_total();
    cout<<"Total marks of 5 subjects is : "<<total<<endl;
    return 0;
}