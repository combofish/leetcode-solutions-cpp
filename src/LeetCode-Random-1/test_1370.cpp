#include "combofish_utils.hpp"
#include <algorithm>
#include <iterator>

string trans(string &s){
  unordered_map<char, int> umap;
  for(const char &c: s)
    ++umap[c];

  for(auto &u:umap){
    cout<< "(" << u.first <<" , "<< u.second << " )"<<endl;
  }

  std::map<char, int> tmp;
  std::transform(umap.begin(), umap.end(), std::inserter(tmp, tmp.begin()),
		 [](std::pair<char,int> a){
		   return std::pair<char, int>(a.first, a.second);
		 });

  for(auto &t: tmp)
    cout<< "(" << t.first <<" , "<< t.second << " )"<<endl;


  int kinds = tmp.size();
  string res = "";
  bool up = true;
  while(res.size() < s.size()){
    if(up){
      up = false;
      for(auto &u:tmp){
	if(u.second > 0){
	  res += u.first;
	  u.second--;
	}
      }
    }else{
      up = true;
      for(auto it = tmp.rbegin(); it != tmp.rend(); it++)
	if(it-> second > 0){
	  res += it->first;
	  it->second--;
	}
    }
  }
  
  
  return res;
}


int main(){
  string s = "leetcode";

  string new_s = trans(s);
  outln(s);
  outln(new_s, "new_s");
  return 0;

}
