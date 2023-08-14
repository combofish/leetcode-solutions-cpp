#include <iostream>


using namespace std;

bool isD(const string &str){
    int lk = 0, rk = (int)str.size() - 1;

    while(lk < rk){
        if(str[lk] != str[rk]) return false;
        ++lk;
        --rk;
    }
    return true;

}
int main(){

    int n;
    n = 5;
// cin>> n;
    string str;
    cout<<n<<endl;

    str = "aacde";

    int steps = 0;
    //int lk = 0, rk = n - 1;

//    while(lk < rk){
//        if(str[lk] == str[rk]){
//            ++lk;
//            --rk;
//        }else{
//            ++steps;
//            if(str[lk] == str[rk-1]) --rk;
//            else if(str[lk + 1] == str[rk]) ++lk;
//            else{
//                ++lk;
//                --rk;
//            }
//        }
//    }
    if(str.size() == 1) return 0;

    while(!isD(str)){
        ++steps;
        if(str.back() != str.front() && str.front() == str[1]){
            // ++steps;
            auto tmp = str.front();
            str = str.substr(1);
            str.push_back(tmp);
        }else{
            int lk = 0, rk = str.size()-1;
            while(lk <= rk){
                if(str[lk] == str[rk]) {
                    ++lk;
                    --rk;
                }else{
                    str[lk] = str[rk];
                    break;
                }
            }
        }

    }

    cout<<steps<<endl;






    return 0;
}