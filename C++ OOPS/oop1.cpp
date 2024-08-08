#include <iostream>
#include <string.h>
using namespace std;
class Teacher {
    private:
        double salary;
    public:
    //properties/ attributes
        string name;
        string dept;
        string subject;

    //methods/ member functions
    void changeDept(string newDept){
        dept = newDept;
    }

    //Indirectly salary is accessible throgh the given public functions
    //setter(setter fn is use to set the private values )
    void setSalary(double s){
        salary = s;
    }
    //getter(use to get the private values )
    double getSalary(){
        return salary;
    }
};
int main(){
    Teacher t1;//default constructor call by compiler
    t1.name = "Pooja";
    t1.subject = "C++";
    t1.dept = "Computer Science";
    t1.setSalary(20000);

    cout << t1.name<<endl;
    cout<<t1.getSalary()<<endl;
return 0;
}