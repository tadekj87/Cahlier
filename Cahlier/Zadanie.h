#pragma once
#ifndef ZADANIE_H_INCLUDED
#define ZADANIE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Zadanie
{

	int r, p, q;// termin dostêpnoœci r(punkt), czas wykonania p(okres), czas dostarczenia q
	int numer_zadania;
	int C;

	Zadanie() { r = p = q = 0; }
	~Zadanie() {}
};

struct kolejnoscR
{
	bool operator ()(const Zadanie& a, const Zadanie& b) const
	{
		return a.r > b.r;
	}
};

struct kolejnoscQ
{
	bool operator ()(const Zadanie& a, const Zadanie& b) const
	{
		return a.q < b.q;
	}
};

#endif // ZADANIE_H_INCLUDED