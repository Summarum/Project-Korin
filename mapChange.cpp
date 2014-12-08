#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
using namespace std;
int ExitsCount;
char *ExitsTab;
string dupa;
string *wyjscia;
char **tabela;  //tabela z mapa
int wymiarA, wymiarB;   //tablica
int posX, posY;

void robTabele(string plik);
void hidecursor();
int colCheck(int a, int b);
void gameLogic();



/**
Funkcja chowajaca kursor

**/
void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 1;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}


/**
Tworzy tabele na podstawie pliku. Plik na poczatku ma wymiary tablicy ktora pozniej funkcja tworzy.

**/
int colCheck(int a, int b){
        if (tabela[a][b] == '#') return 1;

        for(int i=0;i<ExitsCount;i++){
        if((char)(tabela[a][b])==((char)ExitsTab[i])){
              cout << wyjscia[i];
              robTabele(wyjscia[i]);

        return 1;
        }

        }
	return 0;


}
void robTabele(string plik){
	ifstream ifs(plik.c_str());
    delete[] ExitsTab;
    delete[] wyjscia;
    delete[] tabela;
	ifs >> wymiarA >> wymiarB >> posX >> posY >> ExitsCount;
	cout << ExitsCount;
        ExitsTab = new char[ExitsCount];
        wyjscia = new string[ExitsCount];
    for(int i=0;i<ExitsCount;i++){
    ifs >> ExitsTab[i];
    ifs >>wyjscia[i];
    cout<< ExitsTab[i];
    cout << wyjscia[i];

    }
    delete tabela;
	tabela = new char*[wymiarA];
	for (int i = 0; i<wymiarA; i++){
		tabela[i] = new char[wymiarB];
	}
	for (int i = 0; i<wymiarA; i++){
		for (int j = 0; j<wymiarB; j++){

			tabela[i][j] = ifs.get();

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
		cout << posY<<" "<<posX<<endl;
		hidecursor();
		input = getch();
    system("cls");

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

		//system("cls");
	}


}



int main(){
	robTabele("mapa.txt");
	gameLogic();

	getchar();

	return 0;
}
