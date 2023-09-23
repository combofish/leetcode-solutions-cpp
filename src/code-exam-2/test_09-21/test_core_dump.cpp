#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    char *ptr = "hello world!";

    *ptr = 0;

    cout << *ptr << endl;
    return 0;
}
