#include <iostream>
#include <fstream>

using namespace std;

#define MAX(x, y) ( (x > y) ? (x) : (y) )


void biggest_salary(string path) {
	ifstream Statement;
	
	string name, l_name, date;
	double salary, sum, max_salary = 0;
	
	Statement.open(path);
	if(Statement.is_open()) {
		while(!Statement.eof()) {
		
			Statement >> name >> l_name >> salary >> date;
			sum += salary;
			max_salary = MAX(salary, max_salary);
			
		}
		Statement.close();
	
		
		cout <<"Sum is " << sum <<"\n" <<"The biggest salary = " << max_salary << "\n";

	 
		Statement.open(path);
		while(!Statement.eof()) {
		
			Statement >> name >> l_name >> salary >> date;
			if(salary == max_salary) cout <<"The biggest salary has " << name << " " << l_name;
		}
		Statement.close();
	}
	else cout << "could not open the file";
}


int main() {
	string path = "C:\\Users\\Alex_dev\\Desktop\\Prog\\skill\\ReadFromFile\\Files\\statement.txt";

	biggest_salary(path);
}
