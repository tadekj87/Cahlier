#pragma once
#ifndef SCHRAGE_H_INCLUDED
#define SCHRAGE_H_INCLUDED

#include "Zadanie.h"

using namespace std;

extern int n;

class Schrage
{

public:

	Zadanie tablicaSchrage[10000];

	int Cmax;
	int Cmax_bez_podzialu;
	int Cmax_z_podzialem;
	int liczba_zadan;

	bool Wczytaj();
	void Posortuj();
	void Wyswietl() {		
		for (int i = 0; i < liczba_zadan; i++)
			cout << tablicaSchrage[i].r << "\t" << tablicaSchrage[i].p << "\t" << tablicaSchrage[i].q << endl;
	}
	int Schrage_bez_podzialu();
	int Schrage_z_podzialem();

	Schrage() { Cmax = Cmax_bez_podzialu = Cmax_z_podzialem = liczba_zadan = 0; }
	~Schrage(){}
};


#endif // SCHRAGE_H_INCLUDED