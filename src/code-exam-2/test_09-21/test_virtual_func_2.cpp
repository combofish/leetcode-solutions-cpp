#include <iostream>

using namespace std;

class A {
public:
	virtual void func() {
		cout << "A::func()" << endl;
	}
};

class B: public A {
public:
	virtual void func() {
		cout << "B::func()" << endl;
	}
};

void call_func(A& a) {
	a.func();
}
int main() {
	A a;
	B b;
	
	A* c = &b;

	call_func(a);
	call_func(b);
	call_func(*c);


	return 0;
}