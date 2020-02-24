#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <windows.h>
using namespace std;

void polje(char field[][12], int n){
	system("cls");
	for (int i=0;i<n;i++){
		for(int j=0;j<12;j++){
			cout << setw(2) << "0";
		}
		cout << endl;
	}
}

void postavitev(char field[][12]){
	int coordX, coordY, len;
	cout <<"Vpisi dolzino ladjice: ";
	cin >> len;
	cout << endl;
	cout << "Vpisi x koordinato: ";
	cin >> coordX;
	cout << endl;
	cout << "Vpisi y koordinato: ";
	cin >> coordY;
	cout << endl;
	for (int i=0; i<len; i++){
		field[coordX+i][coordY] = {"X"};
	}
}

int main(){
	srand(time(NULL));
	char field[12][12];
	postavitev(field);
	polje(field, 12);
	return 0;
} 	