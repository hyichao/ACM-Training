#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "stringUtil.h"

using namespace std;

#ifndef DEBUG
#define DEBUG false
#endif

//problem change, directory change
static const string directory = "RopeIntranet/";

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


int intersection(vector<pair<int,int> > lines) {

	int count = 0;
	for(int i=0;i<lines.size();i++) {
		for(int j=i;j<lines.size();j++) {
			int diffA = lines[i].first-lines[j].first;
			int diffB = lines[i].second-lines[j].second;
			if(diffA * diffB < 0) {
				count++;
			}
		}
	}
	return count;
}


int main() {

  	string testcase = getNewLine();
  	
  	int test = std::stoi(testcase);

  	for(int i=0;i<test;i++) {
	  	
	  	string nRope = getNewLine();
	  	int n = std::stoi(nRope);
  		
  		vector<pair<int,int> > lines;
	  	
	  	for(int j=0;j<n;j++) {
		  	string vecLine = getNewLine();
		  	vector<int> vec = splitToInts(vecLine, " ");
		  	lines.push_back(std::make_pair(vec[0],vec[1]));
	  	}

	  	int result = intersection(lines);
  		
  		string out = to_string(result);
  		printResult(i+1,out);
  	}

  	return 0;
}







