#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__TOS_WIN__) || defined(__WINDOWS__)
    #include <windows.h>
#endif
using namespace std;

void polja(char player_field[][12], char computer_field[][12], int n){
	system("clear"); //na sistemu Windows dodaj komentar
	//system("cls"); //na sistemu Windows odstrani komentar 
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

	bool winPC, winPlayer, ugibanjePlayer = true, ugibanjePC = false;
	int playerX, playerY,pcX, pcY, stevecPC = 0, stevecPlayer = 0;

	while(true){
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
				cout << "Zadel si!\n";
				if(stevecPlayer==7){
					winPlayer = true;
					winPC = false;
					break;
				}
			}else {
				computer_field[playerX][playerY] = '#';
				ugibanjePlayer = false;
				ugibanjePC = true;
				break;
			}
		}
		while(ugibanjePC){
			pcX = rand()%12;
			pcY = rand()%12;
			if(player_field[pcX][pcY] == 'X'){
				player_field[pcX][pcY] = '@';
				stevecPC++;
				if(stevecPC == 7){
					winPC = true;
					winPlayer = false;
					break;
				}
			}else {
				player_field[pcX][pcY] = '#';
				ugibanjePC = false;
				ugibanjePlayer = true;
				break;
			}
		}
		if(winPlayer){
			cout << "Bravo! Zmagal si!\n";
			break;
		}else if(winPC){
			cout << "Izgubil si... Vec srece prihodnjic!\n";
		}
	}
	polja(player_field, computer_field, 12);	
	return 0;
} 	