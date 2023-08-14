/*
 * @Author: combofish combofish@163.com
 * @Date: 2023-08-07 14:16:15
 * @LastEditors: combofish combofish@163.com
 * @LastEditTime: 2023-08-08 10:04:01
 * @FilePath: /leetcode-solutions-cpp/src/code-exam-2/test_04/test.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <iomanip>
// #include <cstdio>
#include <bitset>

#include <stdio.h>
#include <stdlib.h>

// #include <cstdlib>

using namespace std;

int onLoop(int x){
    cout<< "x = "<<x<<endl;
    return x;
}


int main(){

    // int cnt = 10;
    // while(cnt-- > 0){

    //     double pi = 31415925;
    //     double arg = 0.0000000001;
    //     double oth = 0.0009000009;

    //     double ans1 = (pi + arg) + oth;
    //     double ans2 = pi + (arg + oth);

    //     cout<<std::setprecision(12)<<ans1<<endl;
    //     cout<<std::setprecision(12)<<ans2<<endl;
    // }

    int n = 10;
    for(int i = 0; i< onLoop(n); ++i){
        cout<<"hello world"<<endl;
    }


    float float_num = 8.8;
    cout<<"8.8 的二进制： "<< bitset<8>(float_num)<<endl;
    cout<<"8.8 的十六进制： "<< hex <<float_num <<endl;


    int num = 10;
    char s[10];
    
    // itoa(num, s, 2);
    // _itoa_s(num, s, 2);
    printf("二进制： %s\n", s);

    cout<<num<<endl;

   

    return 0;
}