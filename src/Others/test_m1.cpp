/**
-- method:

--result:

-- analyse:
Time: O()
Space: O()

 */

#include "combofish_utils.hpp"
#include <algorithm>
#include <regex>
#include <string.h>

class Solution {
public:
    // function start.

    // function end.
};

int testFunc(char *s) {
    char *q = s;
    while (*q != '\0') {
        q++;
    }
    return q - s;
}

int main() {

    auto solution = new Solution();

    // code start
    // int a = 1;
    // int *pi = &a;
    // int **ppi = &pi;

    // // code end

    // int arr[]={0,1,2};
    // int *p =arr;

    // double a = 1;
    // int &b = a;


    // int a = 1;
    // int *b = &a;


    // char c[] = "goodluck";
    // printf("%d", testFunc(c));


    // int t = 1;

    // t & 1 ? t++ : t--;
    // IC(t);

    int t = 1;
    // t ^ 1 ? t += t ^ 1 : ++t;
    // IC(t);

    // t = ++t>1?1:t;
    // IC(t);

    // t = t++ > 1 ? 1 : t;
    // IC(t);


    // int a = 0;
    // int b = 1;
    // a += b + 1;
    // a + 1 += b;
    // a = b == 1;
    // a == b = 1;

    // #     char str[5] = "abcde";
    //     char str1[] = {'a', '\0', 'c', 'd', 'e'};
    //     char str5[5] = {'a', 'b', 'c', 'd', '\0'};
    //     char str6[] = "abc\\0";

    // IC(6 & 3);
    // IC(strlen(str1));
    // IC(strlen(str5));
    // IC(strlen(str6));


    // std::regex reg("\\.\\s*");


    // IC(std::regex_match(s1, reg));

    // std::string mail("Alpha. Beta. Gamma.");
    // std::regex reg("\\.\\s*");
    // // std::regex reg("\\.\s*");
    // // std::regex reg("\.\s*");
    // // std::regex reg(".\s*");
    // std::sregex_token_iterator pos(mail.begin(), mail.end(), reg, -1);
    // decltype(pos) end;
    // for (; pos != end; ++pos) {
    //     std::cout << pos->str() << std::endl;
    // }


    // short a = -1;
    // unsigned short b = a;
    // short c = a - b;
    // int d = a - b;
    // printf("%x, %x", c, d);


    unsigned int A = 86, B = 200;
    unsigned int resW = 0, sum = 0;
    unsigned short G = 436, H = 578;
    unsigned short resT = 0;
    resW = B * ((A * 2) / B);
    resT = G * H;
    sum = resW + resT;
    IC(sum);
    delete solution;
    return 0;
}
