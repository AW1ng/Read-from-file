#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int word_seeker(string path, string word) {
	unsigned int count = 0, i = 0;
	vector<string> content;
	string str;
	ifstream words;
	
	words.open(path);
	
	while(!words.eof()) {
		words >> str;
		content.push_back(str);
	}
	
	words.close();
	
	for(i; i < content.size(); i++) {
		if(word == content[i]) count++;
	}
	return count;
}


int main() {
	string Path = "C:\\Users\\Alex_dev\\Desktop\\Prog\\skill\\ReadFromFile\\Files\\words.txt"; // put path here
	cout << word_seeker(Path, "tiger");
}

