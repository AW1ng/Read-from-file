#include <iostream>
#include <fstream>
using namespace std;


void txt_reader(string path) {
	ifstream text(path, ifstream::binary);
	if(text.is_open()) {
		text.seekg(0, text.end);
		int length = text.tellg();
		text.seekg(0, text.beg);
		
		
		char* buffer = new char[length];
		
		text.read(buffer, length);
		text.close();
		
		
		cout.write(buffer, length);
		delete[] buffer;
	}
	else cout << "There is an error occurred!";
	
}


int main() {
	string Path = "C:\\Users\\Alex_dev\\Desktop\\METRO_PROLOG.txt";
	txt_reader(Path);
}
