/* Encapsulation
 It is wrapping up of data/properties & member functions in single unit called class
 helps in data hiding -> using private acess modifier 


class Account {
    private:
        double balance;
        string password;// data hiding
    public:
        string accountId;
        string username;
    }  */

/*Constructor
Special method invoked automatically at time of object creation.
Used for Initialisation.

. Same name as class
. doesn't have a return type
. Only called once(automatically)
. always declared public because call is made from main fn
. Memory allocation happens when constructor is called

*/
#include <iostream>
#include <string.h>
using namespace std;


class Teacher {
    private:
        double salary;
    public:
    //non-parameterized constructor
    Teacher() {
        cout<<"Hi, I am constructor"<<endl;
        dept = "Computer Science";
    }

    //parameterized constructor
    Teacher(string n, string s, double sal) {
        name = n;
        
        subject = s;
        salary = sal;
    }
        string name;
        string dept;
        string subject;

    void changeDept(string newDept){
        dept = newDept;
    }
void getInfo(){
    cout << "name:" <<name <<endl;
    cout << "subject: " <<subject <<endl;
}
};
int main(){
    // Teacher t1;//constructor call
    // cout<<t1.dept;// assigned through constructor 

    Teacher t1("Pooja","C++", 20000);
    t1.getInfo();

//a class can have multiple constructor given their parameters are different->constructor overloading which is an example of polymorphism
return 0;
}