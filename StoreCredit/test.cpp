#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "stringUtil.h"

using namespace std;

vector<int> indexOfFitPrice(int credit, vector<int> prices);

#ifndef DEBUG
#define DEBUG false
#endif

//problem change, directory change
static const string directory = "StoreCredit/";

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

int main() {

  	string num = getNewLine();
  	
  	int n = std::stoi(num);

  	for(int i=0;i<n;i++) {
	  	
	  	string creditStr = getNewLine();
  		int credit = std::stoi(creditStr);

  		string itemStr = getNewLine();
  		int item = std::stoi(itemStr);

  		string pricesStr = getNewLine();
  		vector<int> prices = splitToInts(pricesStr," ");

  		vector<int> twoPrice = indexOfFitPrice(credit, prices);
  		
  		string out = to_string(twoPrice[0]) + " " + to_string(twoPrice[1]);
  		printResult(i,out);
  	}

  	return 0;
}



vector<int> indexOfFitPrice(int credit, vector<int> prices) {

	vector<int> result;
	for(int i=0; i<prices.size(); i++) {
		for(int j=i+1; j<prices.size(); j++) {
			if(prices[i]+prices[j] == credit) {
				result.push_back(i+1);
				result.push_back(j+1);
			}
		}
	}

	return result;
}



