
#include <string>
#include <icecream.hpp>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> split_nums(const string &str){
    string tmp;
    stringstream ss(str);

    vector<string> strs;
    while(std::getline(ss, tmp, '=')){
        strs.emplace_back(tmp);
    }
    int c = - std::stoi(strs.back());

    string first_str = strs.front();
    int sz = first_str.size();
    int rk = 0;
    while(rk < sz){
        if(first_str[rk] == '-' || first_str[rk] == '+'){
            break;
        }
        ++rk;
    }

    string str_a = first_str.substr(0, rk);
    string str_b = first_str.substr(rk+1, sz - rk);

    int a = 1, b = 1;

    if(str_a.back() == 'x' && str_b.back() == 'y'){
        
    }else{
        std::swap(str_a, str_b);
    }

    str_a = str_a.substr(0, str_a.size() - 1);
    str_b = str_b.substr(0, str_b.size() - 1);

    if(str_a.empty()){
        a = 1;
    }else{
        a = std::stoi(str_a);
    }
    
    if(str_b.empty()){
        b = 1;
    }else{
        b = std::stoi(str_b);
    }

    if(first_str[rk] == '-'){
        b = -b;
    }

    return {a, b, c};
}

void process(vector<int> &nums_a, vector<int> &nums_b){

	double a,b,c,d,e,f,x,y;

    a = nums_a[0];
    b = nums_a[1];
    c = nums_a[2];

    d = nums_b[0];
    e = nums_b[1];
    f = nums_b[2];

	y=(double)((-f*1.0+d*c*1.0/a)*1.0/(-d*b*1.0/a+e*1.0));
	x=(double)((-c*1.0-b*y*1.0)*1.0/a);

    cout<< "x="<<int(x)<<endl;
    cout<<"y="<<int(y)<<endl;
}

int main(){

    string a = "x+y=5";
    string b = "2x+4y=12";

    IC(a, b);

    auto nums_a = split_nums(a);
    auto nums_b = split_nums(b);


    IC(nums_a);
    IC(nums_b);

    process(nums_a, nums_b);

    return 0;
}