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
static const string directory = "MinimunScalarProduct/";

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

long long minimun(vector<long> vec1, vector<long> vec2) {

	sort(vec1.begin(),vec1.end());
	sort(vec2.begin(),vec2.end(),std::greater<long>());
	
	long long min=0;
	for(int i=0; i<vec1.size(); i++) {
		min += (long long)vec1[i] * vec2[i];
	}
	return min;
}


int main() {

  	string num = getNewLine();
  	
  	int n = std::stoi(num);

  	for(int i=0;i<n;i++) {
	  	
	  	string line = getNewLine();
  		
	  	string vec1Lie = getNewLine();
	  	vector<long> vec1 = splitToLongs(vec1Lie, " ");
	  	string vec2Line = getNewLine();
	  	vector<long> vec2 = splitToLongs(vec2Line, " ");
  		
  		long long result = minimun(vec1,vec2);
  		string out = to_string(result);
  		printResult(i+1,out);
  	}

  	return 0;
}







