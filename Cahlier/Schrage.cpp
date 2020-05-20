#include "Schrage.h"

using namespace std;

bool Schrage::Wczytaj()
{
	ifstream plik;

	plik.open("SCHRAGE9.DAT", ios::in);

	plik >> liczba_zadan;

	for (int i = 0; i < liczba_zadan; i++)
	{
		plik >> tablicaSchrage[i].r;
		plik >> tablicaSchrage[i].p;
		plik >> tablicaSchrage[i].q;
		tablicaSchrage[i].numer_zadania = i;
	}

	plik.close();

	return true;
}

void Schrage::Posortuj() 
{
	for (int i = 0; i < liczba_zadan; i++)
		for (int j = 0; j < liczba_zadan - 1; j++)
			if (tablicaSchrage[j].r > tablicaSchrage[j + 1].r)
				swap(tablicaSchrage[j], tablicaSchrage[j + 1]);
}

int Schrage::Schrage_z_podzialem()
{
	Cmax = 0;
	int t = tablicaSchrage[0].r;
	Cmax_z_podzialem = 0;

	Zadanie l, e; 
	priority_queue<Zadanie, vector<Zadanie>, kolejnoscR> N;// zbiór N jest porz¹dkowany rosn¹co po mniejszej wartoœci "r"
	priority_queue<Zadanie, vector<Zadanie>, kolejnoscQ> G;// zbiór G jest porz¹dkowany rosn¹co po wiêkszej wartoœci "q"


	l.q = 0; 
	for (int i = 0; i < liczba_zadan; i++)
	{
		N.push(tablicaSchrage[i]);
	}
	while (G.empty()==false || N.empty()==false)
	{
		while (N.empty()==false && N.top().r <= t)
		{
			e = N.top();
			G.push(e); // zadanie "e" dodawane do zbioru G z "czubka" zbioru N
			N.pop(); // œci¹gniêcie "e" z czubka N

			if (e.q > l.q)
			{
				l.p = t - e.r;
				t = e.r;
				if (l.p > 0)
				{
					G.push(l);
				}
			}
		}

		if (G.empty() == true)
		{
			t = N.top().r; // "t" jest równe najmniejszej wartoœci zbioru N
			continue;	// pomija siê dalsze kroki i przechodzi do kolejnej pêtli
		}

		e = G.top(); // "e" jest œci¹gane z czubka "G"
		G.pop();

		l = e;
		t = t + e.p;

		if (Cmax < t + e.q)
			Cmax = t + e.q;

		Cmax_z_podzialem = Cmax;
	}
	return Cmax;
}

int Schrage::Schrage_bez_podzialu()
{

	int t = 0;

	Cmax = 0;

	t = tablicaSchrage[0].r;
	priority_queue<Zadanie, vector<Zadanie>, kolejnoscR> N;
	priority_queue<Zadanie, vector<Zadanie>, kolejnoscQ> G;

	for (int i = 0; i < liczba_zadan; i++)
	{
		N.push(tablicaSchrage[i]);
	}
	int j = 0;
	while (!G.empty() || !N.empty())
	{
		while (!N.empty() && N.top().r <= t)
		{
			G.push(N.top());
			N.pop();
		}
		if (G.empty()==true)
			t = N.top().r;
		else
		{
			tablicaSchrage[j] = G.top();
			t = t + G.top().p;

			if(t+G.top().q>Cmax)
				Cmax = t + G.top().q;
			G.pop();
			tablicaSchrage[j].C = t;
			j++;

		}
		Cmax_bez_podzialu = Cmax;


	}
	return Cmax;
}