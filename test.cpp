#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

//useful functions
string getNewLine();
void printResult(int caseNum, string out);

vector<string> split(const std::string& s, const std::string& c);
vector<int> splitToInts(const std::string& s, const std::string& c);
vector<long> splitToLongs(const std::string& s, const std::string& c);
string reverse(string input);


#ifndef DEBUG
#define DEBUG true
#endif

//problem change, directory change
static const string directory = "FileFixit/";

//input
static const string inputFileName = "A-large-practice.in.txt";
ifstream inputfile(directory+inputFileName);

//output
static const string resultFileName = "result.txt";
ofstream outputfile(directory+resultFileName);

//core implementation
int main() {

  	string testcase = getNewLine();
  	
  	int test = std::stoi(testcase);

  	for(int i=0;i<test;i++) {
	  	
	  	string nk = getNewLine();
	  	

	  	int result = 0;
  		string out = to_string(result);
  		printResult(i+1,out);
  	}

  	return 0;
}

//basic io
string getNewLine() {
	string ret;
  	if (DEBUG) {
  		std::getline(cin,ret);
  	} else {
  		std::getline(inputfile,ret);	
  	}
  	return ret;
}

void printResult(int caseNum, string out) {
	if (DEBUG) {
		cout<<"Case #"<<to_string(caseNum)<<": ";
		cout<<out<<endl;
	} else {
		outputfile<<"Case #"<<to_string(caseNum)<<": ";
		outputfile<<out<<endl;
	}
}

// useful functions implementation
vector<string> split(const std::string& s, const std::string& c) {
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







