#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;
char **tabela;  //tabela z mapa
int wymiarA, wymiarB;   //tablica
int posX, posY;
/**
Tworzy tabele na podstawie pliku. Plik na poczatku ma wymiary tablicy ktora pozniej funkcja tworzy.

**/
int colCheck(int a, int b){
	if (tabela[a][b] == '#') return 1;

	return 0;


}
void robTabele(string plik){
	ifstream ifs(plik.c_str());

	ifs >> wymiarA >> wymiarB >> posX >> posY;

	tabela = new char*[wymiarA];
	for (int i = 0; i<wymiarA; i++){
		tabela[i] = new char[wymiarB];
	}
	for (int i = 0; i<wymiarA; i++){
		for (int j = 0; j<wymiarB; j++){
			/*if (i == posX&&j == posY){
				tabela[i][j] = 'G';
				ifs.get();
				continue;
			}*/
			tabela[i][j] = ifs.get();
			//cout << tabela[i][j]<<i<<j;
			//ifs >>noskipws >>tabela [i][j];
			//cout<<tabela[i][j];
		}
	}
	tabela[posY][posX] = 'G';
}
void gameLogic(){

	char input;
	while (1){
		for (int i = 0; i<wymiarA; i++){
			//cout << "linia" << i;
			for (int j = 0; j<wymiarB; j++){
				cout << tabela[i][j];
			}
		}
		cout << endl;
		input = getchar();


		if (input == 'd'){
			if (colCheck(posY, posX + 1) == 1) continue;
			tabela[posY][posX] = ' ';
			tabela[posY][posX + 1] = 'G';
			posX++;
		}
		if (input == 'a'){
			if (colCheck(posY, posX -1) == 1) continue;
			tabela[posY][posX] = ' ';
			tabela[posY][posX - 1] = 'G';
			posX--;
		}
		if (input == 's'){
			if (colCheck(posY+1, posX) == 1) continue;
			tabela[posY][posX] = ' ';
			tabela[posY + 1][posX] = 'G';
			posY++;

		}
		if (input == 'w'){
			if (colCheck(posY - 1, posX) == 1) continue;
			tabela[posY][posX] = ' ';
			tabela[posY - 1][posX] = 'G';
			posY--;

		}

		system("cls");
	}


}



int main(){
	robTabele("mapa.txt");
	gameLogic();

	getchar();

	return 0;
}
