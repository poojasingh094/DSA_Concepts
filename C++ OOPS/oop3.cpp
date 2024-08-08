// this pointer
// this is a special pointer in C++ that points to the current object.

#include <iostream>
#include <string.h>
using namespace std;

class Teacher {
    private:
        double salary;
    public:
        string name;
        string dept;
        string subject;

    Teacher(string name, string subject, double salary) {//this used to access properties of objects
        this->name = name;
        this->subject = subject;
        this->salary = salary;
    }

void getInfo(){
    cout << "name:" <<name <<endl;
    cout << "subject: " <<subject <<endl;
}
};

int main(){

    Teacher t1("Pooja","C++", 20000);
    t1.getInfo();

return 0;
}

//Copy Constructor
// Special Constructor (default) used to copy properties of one object into another

Teacher t2(t1); //default copy constructor invoke
t2.getInfo();
return 0;

//our custom copy constructor, we can make as
Teacher(Teacher &orgObj) {// pass by reference
    this->name = orgObj.name;
    this->subject = orgObj.subject;
    this->salary = orgObj.salary;
}
/* Whenever objects copied are made, there are two types of copies that can be created 
Shallow & Deep Copy
A shallow copy of an object copies all of the member values from one object to another
A deep copy not only copies the member values but also makes copies of any dynamically allocated memeory that the members point to
*/