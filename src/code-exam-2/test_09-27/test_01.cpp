#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
    string line;

    std::getline(std::cin, line);

    string curr;
    int cnt = 0;

    for(auto &c: line){
        if(c == ',' || c == ' '|| c == '.'){
            if(curr == "the"){
                ++cnt;
            }

            curr.clear();
        }else{
            curr.push_back(c);
        }
    }


    return 0;
}