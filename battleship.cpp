#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
    #include <windows.h>
#endif
#define MAX_DOLZINA 100
using namespace std;

void vpisImena(char ime[]){
	cout << "Vpisi svoje ime: ";
	cin >> ime;
}

void polja(char player_field[][12], char computer_field[][12], int n, char ime[]){
	system("clear"); //na sistemu Windows dodaj komentar
	//system("cls"); //na sistemu Windows odstrani komentar
	cout << "Igralec: " << ime << "\n\n";
	for (int i=0;i<n;i++){
		for(int j=0;j<12;j++){
			cout << setw(2) << player_field[i][j];
		}
		cout << endl;
	}
	cout << "\n\n\n";
	cout << "Racunalnik:\n";
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
	cin >> coordY;
	cout << "Vpisi y koordinato: ";
	cin >> coordX;
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

int main(){
	srand(time(NULL));
	char player_field[12][12];
	char computer_field[12][12];
	char ime[MAX_DOLZINA] = {0};
	vpisImena(ime);
	clearTable(player_field);
	clearTable(computer_field);
	system("clear"); //komentiraj na Windows
	//system("cls")  //odkomentiraj na Windows
	cout << "Postavitev 3-mestne ladjice:\n";
	postavitev_player(player_field, 3);
	cout << "Postavitev prve 2-mestne ladjice:\n";
	postavitev_player(player_field, 2);
	cout << "Postavitev druge 2-mestne ladjice:\n";
	postavitev_player(player_field, 2);
	postavitev_computer(computer_field, 3);
	postavitev_computer(computer_field, 2);
	postavitev_computer(computer_field, 2);
	polja(player_field, computer_field, 12, ime);

	bool winPC, winPlayer, ugibanjePlayer = true, ugibanjePC = false, game = true;
	int playerX, playerY,pcX, pcY;
	int stevecPC = 0, stevecPlayer = 0;

	while(game){
		cout << "Ugibanje igralca:\n";
		while(ugibanjePlayer){
			cout << "Vpisi x in y na katerega bi ciljal (oba med 0 in 11): \n";
			cout << "x: ";
			cin >> playerX;
			cout << "y: ";
			cin >> playerY;
			cout << endl;
			if(computer_field[playerX][playerY] == 'X'){
				computer_field[playerX][playerY] = '@';
				stevecPlayer++;
				cout << "Zadel si!\n\n";
				if(stevecPlayer == 7){
					winPlayer = true;
					winPC = false;
					break;
				}
			}else if(computer_field[playerX][playerY] == '@'){
				cout << "To polje si ze zadel.\n\n";
			}else {
				computer_field[playerX][playerY] = '#';
				cout << "Zgresil si.\n\n";
				ugibanjePlayer = false;
				ugibanjePC = true;
				break;
			}
		}
		while(ugibanjePC){
			cout << "Ugibanje racunalnika.....\n";
			pcX = rand()%12;
			pcY = rand()%12;
			if(player_field[pcX][pcY] == 'X'){
				cout << "Racunalnik je zadel.\n";
				player_field[pcX][pcY] = '@';
				stevecPC++;
				if(stevecPC == 7){
					break;
				}
			}else if(player_field[pcX][pcY] == '@'){
				cout << "Racunalnik je ponovno zadel isto polje.\n";
			}
			else {
				cout << "Racunalnik je zgresil.\n\n";
				player_field[pcX][pcY] = '#';
				ugibanjePC = false;
				ugibanjePlayer = true;
				break;
			}
		}
		if((stevecPlayer==7) || (stevecPC == 7)){
			game = false;
		}
	}
	polja(player_field, computer_field, 12, ime);
	if (stevecPlayer == 7) winPlayer = true;
	else if(stevecPC == 7) winPC = true; 
	if(winPlayer){
		cout << "Bravo! Zmagal si!\n";
	} else if(winPC){
		cout << "Izgubil si... Vec srece prihodnjic!\n";
	}
	return 0;
}