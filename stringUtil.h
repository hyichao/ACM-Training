#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> split(const std::string& s, const std::string& c)
{
  vector<string> v;
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while(std::string::npos != pos2)
  {
    v.push_back(s.substr(pos1, pos2-pos1));
 
    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if(pos1 != s.length())
    v.push_back(s.substr(pos1));

  return v;
}


vector<int> splitToInts(const std::string& s, const std::string& c) {
  
  vector<string> v = split(s,c);
  vector<int> ret;
  for(int i=0; i<v.size();i++) {
    ret.push_back(stoi(v[i]));
  }
  return ret;
}

vector<long> splitToLongs(const std::string& s, const std::string& c) {
  vector<string> v = split(s,c);
  vector<long> ret;
  for(int i=0;i<v.size(); i++) {
    ret.push_back(stol(v[i]));
  }
  return ret;
}


string reverse(string input) {

    vector<string> words = split(input," ");

    vector<string> reverseWords;
    int size = words.size();
    for(int i=0; i<size; i++) {
    	reverseWords.push_back(words[size-i-1]);
    }

    string ret = "";
    for(int i=0; i<size; i++){
    	ret += reverseWords[i];
    	ret += " "; 
    }
    return ret;
}
