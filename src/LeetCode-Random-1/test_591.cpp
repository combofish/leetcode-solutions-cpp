// Error

#include "combofish_utils.hpp"
#include <cctype>
#include <cstdio>

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
  {"<DIV>  unmatched start tag <B>  and unmatched end tag </C>  </DIV>",false}
};

string getCloseTagName(string code){
  code.insert(code.begin() + 1, '/');
  return code;
}

bool checkUp(string &code){
  int n = code.size() - 2;
  if (n<1 || n> 9) return false;
  
  for(const char c: code){
    if(!isalpha(c)) continue;
    if (!isupper(c))
      return false;
  }

  return true;
}

bool checkCloseTagNameExist(string &code, string &close_tag_name){
  int n = code.size();
  int k = close_tag_name.size();

  //   cout<< "code.substr(n-k): " << code.substr(n-k)<<endl;
  if(close_tag_name == code.substr(n-k)) return true;

  outln(close_tag_name, "not closed");
  return false;
}

bool isValid(string code){
  outln(code, ">>>in string");
  
  // if( code.front() != '<' || code.back() != '>') return false;

  string::size_type position_start = code.find_first_of('<');
  string::size_type position_end = code.find_first_of('>');
  if(position_start == code.npos || position_end == code.npos || position_start >= position_end) {
    return false;
  }
  
  string tag_name = code.substr(position_start, position_end+1);
  string close_tag_name = getCloseTagName(tag_name);

  if(!checkUp(tag_name)) return false;
  if(!checkCloseTagNameExist(code, close_tag_name)) return false;

  string tag_content = code.substr(position_end + 1).substr(0, code.size() - tag_name.size()*2 -1);

  
  outln(tag_name, "tag_name");
  outln(tag_content,"tag_content");
  outln(close_tag_name, "close_tag_name");
  cout<<endl;

  string::size_type position_start_second = tag_content.find_first_of('<');

  bool res = true;
  if(position_start_second != tag_content.npos && position_start_second + 1 != tag_content.size()){
    string sub_content = tag_content.substr(position_start_second);
    char next_char = tag_content[position_start_second + 1];

    outln(sub_content, "sub sub str");
    outln(next_char, "next_char");

    if(next_char == '!'){
      if(sub_content.size() < 11 ) {
	return false;
      }

      string cdata_start = sub_content.substr(0,9);
      outln(cdata_start, "cdata_start");
      if(cdata_start != "<![CDATA["){
	cout<< "Err cdata start"<<endl;
	return false;
      }

      string::size_type position_end_second = sub_content.find("]]>");
      outln(position_end_second, "position_end_second");
      outln(sub_content.npos, "npos");
      outln(string::npos, "strng::npos");
      
      
      if(position_end_second == sub_content.npos) {
	cout<< "Err cdata end"<<endl;
	return false;
      }
      
      
      // outln("cdata next");
      
      
    }else if(isupper(next_char)){
      string::size_type position_end_second = sub_content.find_last_of('>');
      if(position_end_second == tag_content.npos && position_start_second >= position_end_second){
	cout<< "sub not closed!"<<endl;
	return false;
      } 
      
      res = isValid(sub_content.substr(0, position_end_second+1));
    }
  }
  
  return res;
}

int main(){
  int n = data.size();
  for(int i = 0 ; i< 1; ++i){
    if(isValid(data[i].first) == data[i].second)
      cout<< "Check "<< i << " passed! : "<< data[i].first <<endl;
  }
  
  return 0;
}
