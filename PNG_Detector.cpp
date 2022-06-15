#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool is_png(const char* c) {
	if(c[0] == -119) return true;
	else return false;	
}

void PNG_detector(string path) {
	ifstream picture(path, ios::binary);
	if(picture.is_open()) {
		
		char* buffer = new char[8];
		picture.read(buffer, sizeof(buffer));
		
//		cout << hex <<  reinterpret_cast<char*>(buffer);
//		HexOut(buffer, 4);

		if(is_png(buffer)) cout << "PNG";
		else cout << "Not PNG";
		picture.close();
		delete buffer;
	}
	else cout << "No such file or directory!";
}


int main() {
	char* path = ".png";
//	char* path = ".txt";
	PNG_detector(path);
}



