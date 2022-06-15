#include <iostream>
#include <fstream>
#include <time.h>
#include <windows.h>
#include <conio.h>

using namespace std;

int get_random(int from = 2, int to = 13) {
	srand( time(0) );
	int result = rand() % (to - from) + 1;
	return result;
}


//void SourceData() {
//	bool check_sector[13];
//	int Sector[13]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
//	int p_score, ai_score;
//	for(int i = 0; i <= 13; i++) {
//		check_sector[i] = true;
//	}
//}


void Scoreboard(string text, string answer, int &p_score, int &ai_score) {
	int Line = 1;
//	create default string
	if(text == answer) {
		cout <<"The answer is " << text << " your answer is " << answer <<"\nYou are right!\n";
		p_score += 1;
	}
	else{
		cout <<"The answer is " << text << " your answer is " << answer << '\n';
		ai_score += 1;	
	}
	cout << "SCORE:\nPLayer: " << p_score << " AI: " << ai_score << '\n';
	
}

void get_question(string path_qest, int q_number) {
	ifstream Questions(path_qest);
	int Line = 1; 
	string text;
	if( Questions.is_open() ) {
		
		while(getline(Questions, text)) { 
			if (Line == q_number) cout << text;
			Line++;
		}	
	}
	else cout << "GET QUESTIONS ERROR\n";
	Questions.close();
}

void get_answers(string path, int q_number, string answer, int &p_score, int &ai_score) {
	ifstream Answers(path);
	int Line = 1, AIScore, PlayerScore; 
	string text;
	if( Answers.is_open() ) {
		
		while(getline(Answers, text)) { 
			if (Line == q_number) {
				Scoreboard(text, answer, p_score, ai_score);
			}
			Line++;
		}
	}
	else cout << "GET ANSWERS ERROR\nSomething went wrong...\n";
	Answers.close();
}


int change_sector(int *A, int num, bool *check_sector, int size = 13) {
	
	int begin = 0; int end = size;
	cout <<"Copy sector: ";
	int j , i = 0;
	
	cout << '\n';
	if(check_sector[num] == true) {
		check_sector[num] = false;
			return num;
		}
	cout <<"Copy sector after: ";
	for(i = 0; i < size; i++) {
		cout << check_sector[i] << ' ';
	}
	

	cout << "FALSE IS " << num <<'\n';
	j = num;
	while(check_sector[j] != true && j < size) {
		if(j == size){
			j = 1;
		}
		j++;
			
//		if(j == num ) cout << "no free sectors!"; // FIX IT
	}
	
	if(check_sector[j] == true) {
		cout <<"True HERE " << j <<'\n'; 
		check_sector[j] = false;
		return j;
	}	
			
}


void Roulette(int *Data, bool *sector) {
	int num = 0, j = 0, new_sector;
	int p_score = 0, ai_score = 0;
	bool check_winner = false;
	string path_questions = "C:\\Users\\Alex_dev\\Desktop\\Prog\\skill\\ReadFromFile\\Files\\uestions.txt";
	string path_answers = "C:\\Users\\Alex_dev\\Desktop\\Prog\\skill\\ReadFromFile\\Files\\nswers.txt";
	string answer;
	cout << "To spin press space button\n";
	while(1){
		if( kbhit() && !check_winner ) {
			switch( getch() ) {
				case 32:
					cout <<"Sector: " << get_random() << "\n";
					for(int i = 0; i < 1; i++) {
						cout << j <<' ';
						num = get_random();
						new_sector = change_sector(Data, num, sector);

						get_question(path_questions, new_sector);
						cout << "\nAnswer: ";
						cin >> answer;
						cout << "here we go ";
						get_answers(path_answers, new_sector, answer, p_score, ai_score);
						
						if(p_score == 6){
							cout << "Player Win!\n";
							check_winner = true;
							exit(1);
						} 
						if(ai_score == 6) {
							cout << "AI Win!\n";
							check_winner = true;
							exit(1);
						}
					}
					j++;
					break;
					
				default: cout << "press space!\n";
			}
		}
	}
}


int main() {
	bool check_sector[13];
	int Sector[13]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	for(int i = 0; i <= 13; i++) {
		check_sector[i] = true;
	}
	
	string path_questions = "C:\\Users\\Alex_dev\\Desktop\\Prog\\skill\\ReadFromFile\\Files\\uestions.txt";
	string path_answers = "C:\\Users\\Alex_dev\\Desktop\\Prog\\skill\\ReadFromFile\\Files\\nswers.txt";
	string answer;
	
	Roulette(Sector, check_sector);

//	int Size = 0;
//	int *A = new int[Size];
	
//	delete[] A;
}






//int change_sector(int *A, int num, int size = 13) {
//	cout <<"Copy sector: ";
//	int j, i;
//	for(i = 0; i < size; i++) {
//		cout << "A " << A[i] << " NUm = " << num <<' ';
////		Data[i] = A[i];
////		cout << "Data[i] " << Data[i] << " A[i]= " << A[i] <<'\n';
//	}
//}

