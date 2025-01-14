#include<bits/stdc++.h>
using namespace std;

class Teacher{
public:
    string name;
    string dept;
    string subject;
    double salary;

    void changeDept(string newDept){
        dept = newDept;
    }
};

int main(){
    Teacher t1;
    t1.name = "Raman";
    t1.dept = "IT";
    t1.subject = "oops";
    t1.salary = 20000;
    cout<< t1.name;
    return 0;
}