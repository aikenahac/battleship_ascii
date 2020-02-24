#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;

void polja(char player_field[][12], char computer_field[][12], int n){
	system("clear");
	for (int i=0;i<n;i++){
		for(int j=0;j<12;j++){
			cout << setw(2) << player_field[i][j];
		}
		cout << endl;
	}
	cout << "\n\n\n";
	for (int i=0;i<n;i++){
		for(int j=0;j<12;j++){
			cout << setw(2) << computer_field[i][j];
		}
		cout << endl;
	}
}

void postavitev_player(char player_field[][12], int len){
	int coordX, coordY;
	cout << "Vpisi x koordinato: ";
	cin >> coordX;
	cout << "Vpisi y koordinato: ";
	cin >> coordY;
	cout << endl;
	if(coordX >= 9){
		coordX = coordX - len + 1;
	}
	for (int i=0; i<len; i++){
		player_field[coordY][coordX+i] = 'X';
	}
}

void postavitev_computer(char computer_field[][12], int len){
	int coordXPC = rand()%(12-len+1);
	int coordYPC = rand()%12;
	for (int i=0; i<len;i++){
		computer_field[coordYPC][coordXPC+i] = 'X';
	}
}

void clearTable(char field[][12]){
	for(int i=0;i<12;i++){
		for(int j=0;j<12;j++){
			field[i][j] = '0';
		}
	}
}

void igralec_ugiba(char computer_field[][12], char player_field[][12]){
	int x, y;
	cout << "Vpisi x: ";
	cin >> x;
	cout << "Vpisi y: ";
	cin >> y;
	if(computer_field[x][y] == 'X'){
		computer_field[x][y] = '@';
		igralec_ugiba(computer_field, player_field);
	}else{
		computer_field[x][y] = '#';
		racunalnik_ugiba(player_field, computer_field);
	}

}

void racunalnik_ugiba(char player_field[][12], char computer_field[][12]){
	int x = rand()%12;
	int y = rand()%12;
	if(player_field[x][y] == 'X'){
		player_field[x][y] = '@';
		racunalnik_ugiba(player_field, computer_field);
	}else{
		computer_field[x][y] = '#';
		igralec_ugiba(computer_field, player_field);
	}
}

int main(){
	srand(time(NULL));
	char player_field[12][12];
	char computer_field[12][12];
	clearTable(player_field);
	clearTable(computer_field);
	cout << "Postavitev 3-mestne ladjice:\n";
	postavitev_player(player_field, 3);
	cout << "Postavitev prve 2-mestne ladjice:\n";
	postavitev_player(player_field, 2);
	cout << "Postavitev druge 2-mestne ladjice:\n";
	postavitev_player(player_field, 2);
	postavitev_computer(computer_field, 3);
	postavitev_computer(computer_field, 2);
	postavitev_computer(computer_field, 2);
	polja(player_field, computer_field, 12);
	igralec_ugiba(computer_field, player_field);
	polja(player_field, computer_field, 12);
	return 0;
} 	