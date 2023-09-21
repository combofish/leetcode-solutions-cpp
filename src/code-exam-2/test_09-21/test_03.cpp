#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void out() {
        cout << "out func" << endl;
    }

    virtual void out(int a){
        cout<< "virtual out func: "<< a <<endl;
    }

    Solution(){
        cout<<"Constructed"<<endl;

        out();

        out(10);
    }
};

int main() {

    //cout << "hello world" << endl;

    Solution sol;

    sol.out();

    return 0;
}