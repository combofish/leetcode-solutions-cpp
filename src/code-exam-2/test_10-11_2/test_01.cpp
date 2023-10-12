#include <iostream>

using namespace std;

char *init_char(void) {
    char p[] = "hello world";
    return p;
}

void Test(void) {
    char *str = nullptr;
    str = init_char();
    cout << str << endl;
}
int main() {

    Test();
    return 0;
}