// Error

#include "combofish_utils.hpp"
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <string>

vector<pair<string, bool>> data = {
  {"<D> <![CDATA[  > </D>", false},
  {"<D>uuu <B>uuu</B> uuu </D>", true},
  {"<DIV>This is the first line <![CDATA[<div>]]></DIV>", true},
  {"<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>", true},
  {"<A>  <B> </A>   </B>",false},
  {"<DIV>  div tag is not closed  <DIV>",false},
  {"<DIV>  unmatched <  </DIV>",false},
  {"<DIV> closed tags with invalid tag name  <b>123</b> </DIV>",false},
  {"<DIV> unmatched tags with invalid tag name  </1234567890> and <CDATA[[]]>  </DIV>",false},
  {"<DIV>  unmatched start tag <B>  and unmatched end tag </C>  </DIV>",false},
  {"<DIV>This is the first line <![CDATA[<<<<<<<]]></DIV>", true},
  {"<![CDATA[wahaha]]]><![CDATA[]> wahaha]]>", false}
};


bool isValid2(string code){
  // outln(code, ">>>in string");
  int n = code.size();
  stack<string> tags;

  int i = 0;
  while(i<n){
    if(code[i] == '<'){
      if(i == n -1) return false;
      if(code[i+1] == '/'){
	int j = code.find('>', i);
	if(j == string::npos) return false;
	string tag_name = code.substr(i+2, j - (i+2));
	if(tags.empty() || tags.top() != tag_name) return false;
	tags.pop();
	i = j + 1;
	if(tags.empty() && i != n) return false;
      }else if(code[i+1] == '!'){
	if(tags.empty()) return false;
	string cdata = code.substr(i+2, 7);
	if(cdata != "[CDATA[") return false;
	int j = code.find("]]>",i);
	if(j == string::npos) return false;
	cout<<i<<","<< j<<" " <<code.substr(j)<< " "<< code.substr(j+3)<<endl;
	i = j + 3;
      }else{
	int j = code.find('>',i);
	if (j == string::npos) return false;
	string tag_name = code.substr(i+1, j-(i+1));
	if(tag_name.size() < 1 || tag_name.size() > 9) return false;
	if(!std::all_of(tag_name.begin(), tag_name.end(),
			[](unsigned char c){
			  return std::isupper(c);
			})) return false;
	tags.push(move(tag_name));
	i =  j + 1;
      }
    }else{
      if(tags.empty()) return false;
      ++i;
    }
  }
  return tags.empty();
}

bool isValid(string code) {
  int n = code.size();
  stack<string> tags;

  int i = 0;
  while(i<n){
    if(code[i] == '<'){
      if(i+1 == n) return false;
      if(code[i+1] == '/'){
	int j = code.find('>', i);
	if(j == string::npos) return false;
	string tag_name = code.substr(i+2, j - (i +2));
	if(tags.empty() || tags.top() != tag_name) return false;
	tags.pop();
	i = j + 1;
	if(tags.empty() && i != n) return false;
      }else if(code[i+1] == '!'){
	if(tags.empty()) return false;
	string cdata = code.substr(i+2, 7);
	if( cdata != "[CDATA[") return false;
	int j = code.find("]]>", i);
	if(j == string::npos) return false;
	i = j + 3;
      }else{
	int j = code.find('>', i);
	if( j == string::npos) return false;
	string tag_name = code.substr(i+1, j - (i+1));
	if(tag_name.size() < 1 || tag_name.size() > 9) return false;
	if(!all_of(tag_name.begin(), tag_name.end(), [](unsigned char c){
	  return isupper(c);
	})) return false;
	tags.push(move(tag_name));
	i = j + 1;
      }
    }else{
      if(tags.empty()) return false;
      ++i;
    }
  }

  return tags.empty();
}

int main(){
  int n = data.size();
  for(int i = n-1 ; i< n; ++i){
    if(isValid(data[i].first) == data[i].second)
      cout<< "Check "<< i << " passed! : "<< data[i].first <<endl;
  }

  IC(n);
  return 0;
}
