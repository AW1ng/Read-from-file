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
	char* path = "C:\\Users\\Alex_dev\\Pictures\\God of War\\1.png";
//	char* path = "C:\\Users\\Alex_dev\\Desktop\\GitCommands.txt";
	PNG_detector(path);
}


//	std::size_t pos = path.find(".");
//	string str = path.substr(pos);
//	picture.seekg(pos, picture.end);
//	int length = picture.tellg();
//	picture.seekg(pos, picture.beg);
	
	
//	void HexOut(const char* c, int len) {
//	for(int i = 0; i < len; i++) {
//		cout.width(2);
//		cout.fill('0');
//		cout << hex << static_cast<unsigned short>(c[i]) <<' ';
//		if(c[0] == -119) cout << "PNG";
//	}
//	if(is_png(c)) cout << "PNG";
//	else cout << "Not PNG";
//}

