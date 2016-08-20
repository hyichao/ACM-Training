#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void split(const std::string& s, std::vector<std::string>& v, const std::string& c);
string reverse(string input);

int main() {

    //input
    ifstream inputfile("B-large-practice.in.txt");

    //output
    ofstream outputfile("result.txt");

  	string num;
  	std::getline(inputfile,num);
  	int n = std::stoi(num);

  	for(int i=0;i<n;i++) {
	  	string input;
  		std::getline(inputfile,input);

  		string output = reverse(input);
  		outputfile<<"Case #"<<to_string(i+1)<<": "<<output<<endl;
  	}

  	return 0;
}

string reverse(string input) {

	vector<string> words;
    split(input, words, " ");

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

void split(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
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
}

