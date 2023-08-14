/**
-- question:
-- method:
 - []

--result:

-- analyse:
Time: O()
Space: O()
 */

#include "../combofish_utils.hpp"

class Parent {
public:
    Parent() {
        cout << "Parent constructed." << endl;
    }

    ~Parent() {
        cout << "Parent deconstructed." << endl;
    }
};

class Son : public Parent {
public:
    Son() {
        cout << "Son constructed." << endl;
    }
    ~Son() {
        cout << "Son deconstructed." << endl;
    }
};

class Solution {

    // function start.
public:
private:
    // function end.
};

int main() {

    auto solution = std::make_shared<Solution>();

    // code start

    Parent *s = new Son();
    delete s;
    // Parent constructed.
    // Son constructed.
    // Parent deconstructed.

    cout<<endl<<endl;


    Son *p_son = new Son();
    delete p_son;
    // Parent constructed.
    // Son constructed.
    // Son deconstructed.
    // Parent deconstructed.

    cout<<endl<<endl;

    Son son;
    IC(son);
    // Parent constructed.
    // Son constructed.
    // ic| son: {}
    // Son deconstructed.
    // Parent deconstructed.

    // code end

    return 0;
}