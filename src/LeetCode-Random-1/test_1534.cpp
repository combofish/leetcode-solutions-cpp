#include "combofish_utils.hpp"

bool check_good(int a1, int a2, int a3, int a, int b, int c){
  if( std::abs(a1 - a2) <= a &&
      std::abs(a2 - a3) <= b &&
      std::abs(a1 - a3) <= c){

    cout<< "("<< a1 <<","<< a2<<","<<a3<<")"<<endl;
    
    return true;
  }
  return false;
}

int main(){
  vec_t nums = {3,0,1,1,9,7};
  int res = 0;

  int a = 7;
  int b = 2;
  int c = 3;
  
  int n = nums.size();

  for(int i = 0; i< n -2; ++i){
    for(int j = i+1; j < n -1; ++j){
      for(int k = j + 1; k < n; ++k){
	if(check_good(nums[i], nums[j], nums[k], a,b,c)) res++;
      }
    }

  }

  

  outln(res);
  return 0;
}
