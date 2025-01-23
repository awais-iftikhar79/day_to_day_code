#include<iostream>
#include<string>
using namespace std;

enum months{January=1,Feburary,March,April,May ,June,July,August ,September,October,November,December};
int main(){
    string months_name[]={"","January","Feburary","March","April","May" ,"June","July","August" ,"September","October","November","December"};
    cout<<"Enter number of month"<<endl;
    int m;
    cin>>m;
    cout<<"The coressponding month is : "<<months_name[m] <<endl;
    return 0;
}