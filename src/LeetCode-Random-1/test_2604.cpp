#include "combofish_utils.hpp"
int trans(vec_t & nums){
  int n = nums.size()/2;
  unordered_map<int,int> umap;
  for(const int &i: nums){
    if(++umap[i] > n)
      return i;
  }

  return -1;
}


int main(){
  vec_t nums = {1,2,5,9,5,9,5,5,5};
  int res =   trans(nums);
  outln(res);
  
  return 0;

}
