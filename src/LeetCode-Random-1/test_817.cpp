

#include "combofish_utils.hpp"

int numComponents(ListNode* head, vec_t& nums){
  unordered_set<int> uset;
  for(const int &i: nums)
    uset.insert(i);

  IC(uset);
  int res = 0;
  ListNode* curr = head;
  while(curr != nullptr){
    if(uset.find(curr->val) != uset.end() && (curr->next == nullptr || uset.find(curr->next->val) == uset.end())){
      ++res;
    }

    curr = curr->next;
  }
  
  return res;
}

int main(){
  // vec_t nums = {1,2,3,4};
  // ListNode* input = new ListNode(0);
  // ListNode* cur = input;

  // for(auto &i : nums){
  //   cur->next = new ListNode(i);
  //   cur = cur->next;
  // }

  vec_t heads = {0,1,2,3,4};
  vec_t nums = {0,3,1,4};
    
  ListNode* input = vec_t2list_node(heads);

  out_list_node(input);
  IC(numComponents(input, IC(nums)));
 
  return 0;
}
