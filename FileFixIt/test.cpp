#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

#include "stringUtil.h"

using namespace std;

#ifndef DEBUG
#define DEBUG false
#endif

//problem change, directory change
static const string directory = "FileFixit/";

//input
static const string inputFileName = "A-large-practice.in.txt";
ifstream inputfile(directory+inputFileName);

//output
static const string resultFileName = "result.txt";
ofstream outputfile(directory+resultFileName);

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

int extraMkdirs(map<string,bool> existed, map<string,bool> wanted) {

	int count = 0;
	for(auto want : wanted) {
		if(existed[want.first] != true) {
			count ++;
		}
	}
	return count;
}

vector<string> analyze(string path) {

	vector<string> ret;
	ret.push_back(path);
	for(int i=path.length()-1; i>0; i--) {
		if(path[i]!='/'){
			continue;
		}
		path = path.substr(0,i);
		ret.push_back(path);
	}
	return ret;
}


int main() {

  	string testcase = getNewLine();
  	
  	int test = std::stoi(testcase);

  	for(int i=0;i<test;i++) {
	  	
	  	string nm = getNewLine();
	  	vector<int> vec = splitToInts(nm," ");
	  	int n = vec[0];
	  	int m = vec[1];
  		
  		vector<string> existPaths;
  		for(int i=0;i<n;i++) {
  			string path = getNewLine();
  			existPaths.push_back(path);
  		}

  		vector<string> wantedPaths;
  		for(int i=0;i<m;i++) {
  			string path = getNewLine();
  			wantedPaths.push_back(path);
  		}

  		map<string,bool> exist;
  		for(string path: existPaths) {
  			vector<string> ret = analyze(path);
  			for(string r: ret) {
  				exist[r] = true;
  			}
  		}

  		map<string,bool> wanted;
  		for(string path: wantedPaths) {
			vector<string> ret = analyze(path);
  			for(string r: ret) {
  				wanted[r] = true;
  			}
  		}

	  	int result = extraMkdirs(exist,wanted);
  		
  		string out = to_string(result);
  		printResult(i+1,out);
  	}

  	return 0;
}







