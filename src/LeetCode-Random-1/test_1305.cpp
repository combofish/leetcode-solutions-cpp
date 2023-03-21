#include "combofish_utils.hpp"

TreeNode *in_1_node = new TreeNode(2, new TreeNode(1), new TreeNode(4));
TreeNode *in_2_node = new TreeNode(1, new TreeNode(0), new TreeNode(3));

void innorder(TreeNode *node, vec_t &res){
  if(node){
    innorder(node->left, res);
    res.push_back(node->val);
    innorder(node->right, res );
  }
}

int main(){
  vec_t res;

  vec_t nums1;
  vec_t nums2;
  innorder(in_1_node, nums1);
  innorder(in_2_node, nums2);

  out_vec(nums1);
  out_vec(nums2);

  auto p1 = nums1.begin(), p2 = nums2.begin();
  while(true){
    if(p1 == nums1.end()){
      res.insert(res.end(), p2, nums2.end());
      break;
    }
    if(p2 == nums2.end()){
      res.insert(res.end(), p1,  nums1.end());
      break;
    }
    if(*p1 < *p2){
      res.emplace_back(*p1++);
    }else{
      res.emplace_back(*p2++);
    }
  }
  
  
  out_vec(res);

  return 0;
}
