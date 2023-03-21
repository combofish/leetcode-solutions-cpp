

#include "combofish_utils.hpp"
#include <string>

unordered_map<char, char> umap = {{'0','0'}, {'1','1'}, {'2','5'},{'5','2'},{'6','9'},{'9','2'},{'8','8'}};

int rotatedDigits(int n){

  int res = 0;

  for(int i = 1; i<= n; ++i){
    string str_n = std::to_string(i);
    string turned_str;
    
    for(const char &c: str_n){
      if(c == '3' || c == '4' || c == '7') break;

      turned_str += umap[c];    
    }

    IC(str_n, turned_str);
    
    if(turned_str.size() != str_n.size()) continue;
    if(str_n == turned_str) continue;
    ++res;
  }
  return res;
}

int main(){
  int n = 10;
  
  IC(rotatedDigits(n));
  
  return 0;
}
