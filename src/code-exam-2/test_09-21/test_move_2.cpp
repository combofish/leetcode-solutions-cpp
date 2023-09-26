#include <iostream>
#include <vector>

using namespace std;

class Demo {
public:
    Demo() : p_num(new int(10)) {
        cout << "Construct" << endl;
    }

    Demo(const Demo &d) : p_num(new int(*d.p_num)) {
        cout << "Copy construct" << endl;
    }

    ~Demo() {
        delete p_num;
        cout << "class destruct!" << endl;
    }

    // Demo(Demo &&d) : p_num(d.p_num) {
    //     d.p_num = nullptr;
    //     cout << "move construct" << endl;
    // }

    int get_num() {
        return *p_num;
    }

private:
    int *p_num;
};

Demo get_demo() {

    // auto a = ;
    return Demo();
}
int main() {

    Demo a = get_demo();

    cout << a.get_num() << endl;

    return 0;
}

/**
 * 
 * 

$ g++ test_move_2.cpp -fno-elide-constructors -std=c++0x -o a.out && ./a.out
Construct
Copy construct
class destruct!
Copy construct
class destruct!
10
class destruct!


$ g++ test_move_2.cpp -fno-elide-constructors -std=c++0x -o a.out && ./a.out
Construct
move construct
class destruct!
move construct
class destruct!
10
class destruct!


*/