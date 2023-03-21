/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>

class Solution {
public:
    // function start.

    // function end.
};

void fun(char **p) {
    int i;
    for (i = 0; i < 4; i++) {
        printf("%s", p[i]);
    }
}
int main() {

    auto solution = new Solution();

    // code start

    // char ch[80] = "123abcdEFG*&";
    // int j;
    // puts(ch);
    // for (j = 0; ch[j] != '\0'; j++)
    //     if (ch[j] >= 'A' && ch[j] <= 'Z')
    //         ch[j] = ch[j] + 'e' - 'E';

    // puts(ch);
    // // code end

    // int a, b, c, x;
    // a = b = c = 0;
    // x = 35;
    // if (!a) x--;
    // else if (b)
    //     ;
    // if (c) x = 3;
    // else
    //     x = 4;

    // IC(x);

    // 9

    // char *s[6] = {"ABCD", "EFGH", "IJKL", "MNOP", "QRST", "UVWX"};
    // fun(s);
    // printf("\n");

    // int a, b, c, d;
    // a = 10110;
    // b = 386;
    // c = 0xffa;
    // //d = x2a2;
    // IC(a, b, c);


    //    int a, b, c, d;
    // a = oxff;
    // b = 0Xabc;
    // c = 0x01;
    // d = 0X9X;

    int a = 0, b = 0, c = 0, d = 0;
    a = b = c = d = 100;
    d++;
    //    c + b;
    d = (c = 22) - (b++);

    IC(a, b, c, d);
    delete solution;
    return 0;
}
