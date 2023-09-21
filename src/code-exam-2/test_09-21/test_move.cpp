#include <iostream>
#include <vector>

using namespace std;

class A{
    public:
    int x;
    A(int x):x(x){
        cout<<"Constructor"<<endl;
    }
    A(A&a): x(a.x){
        cout<<"Copy constructor"<<endl;
    }

    A& operator=(A&a){
        x = a.x;
        cout<<"Copy assignment operator"<<endl;
        return *this;
    }

    A(A&&a): x(a.x){
        cout<<"Move constructor"<<endl;
    }

    A& operator=(A&&a){
        x = a.x;
        cout<< "Move assignment operator"<<endl;
        return *this;
    }
};

int main(){

    A a(10); // Constructor
    A b = a; // Copy Constructor
    A c(a); // Copy Constructor

    b = a;  // Copy assignment operator
    A e = move(a);

    return 0;
}