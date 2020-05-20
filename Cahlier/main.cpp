
//main.cpp Cahlier : Ten plik zawiera funkcję „main”.W nim rozpoczyna się i kończy wykonywanie programu.
// Grupa: WT 13: Junak Tadeusz, Karol Kędzia

#include <iostream>
#include <fstream>
#include <sstream>


#include "Carlier.h"

using namespace std;

int main()
{
	Carlier carlier;
	carlier.Wczytaj();
	carlier.Posortuj();

	cout << "Wartosc funkcji celu U to: " << carlier.carlier_funkcja() << endl;
	system("PAUSE");
	return 0;
}