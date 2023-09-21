#include <iostream>
#include <vector>

using namespace std;

class FunctionConst {
private:
    int value;

public:
    FunctionConst() : value(100){};

    virtual ~FunctionConst(){};

    const int getValue() {
        return value;
    };
    int getValue2() const {
        // value = 15;
        return value;
    };

    // static void getValue3() const{ // error
    //     return;
    // }
};

int main() {

    FunctionConst fc;
    cout << fc.getValue2() << endl;
    cout << fc.getValue() << endl;


    return 0;
}