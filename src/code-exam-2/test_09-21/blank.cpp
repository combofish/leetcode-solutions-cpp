#include <icecream.hpp>
#include <iostream>
#include <memory>

using namespace std;

class B;
class A {
public:
    // shared_ptr<B> p_b;
    weak_ptr<B> pb_weak;
    ~A() {
        cout << "A::Destruction" << endl;
    }
};

class B {
public:
    shared_ptr<A> p_a;
    ~B() {
        cout << "B::Destruction" << endl;
    }
    void out(){
        cout<<"B::out()"<<endl;
    }
};

int main() {

    shared_ptr<B> pb(new B());
    IC(pb.use_count());

    shared_ptr<A> pa(new A());
    IC(pa.use_count());

    pb->p_a = pa;
    IC(pa.use_count(), pb.use_count());

    pa->pb_weak = pb;
    IC(pa.use_count(), pb.use_count());

    auto p = pa->pb_weak.lock();
    p->out();

    IC(pa.use_count(), pb.use_count());



    return 0;
}