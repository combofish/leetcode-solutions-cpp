#include <icecream.hpp>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

void func() {
    shared_ptr<string> pa(new string("CHN"));
    shared_ptr<string> pb(new string("USA"));

    IC(*pa, pa.use_count(), *pb, pb.use_count());

    pa = pb;
    IC(*pa, pa.use_count(), *pb, pb.use_count());


    pa.reset();
    pb.reset();
    IC(pa.use_count(), pb.use_count());
}

int main() {
    func();

    // int *p = new int(10);
    // shared_ptr<int> sp1(p), sp2(p);

    return 0;
}