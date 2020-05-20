#include "Carlier.h"

int Carlier::Znajdz_a(int b)
{
	int suma_a = 0, a;

	for (a = 0; a <= b; a++)
	{
		suma_a = 0;
		for (int i = a; i <= b; i++)
		{
			suma_a += tablicaSchrage[i].p;
		}

		if (Cmax_bez_podzialu == (tablicaSchrage[a].r + suma_a + tablicaSchrage[b].q))
		{
			return a;
		}
	}
	return a;
}

int Carlier::Znajdz_b()
{
	int b = liczba_zadan - 1;

	for (int i = liczba_zadan - 1; i > 0; i--)
	{
		if (Cmax_bez_podzialu == (tablicaSchrage[i].C + tablicaSchrage[i].q))
		{
			b = i;
			break;
		}
	}
	return b;
}

int Carlier::Znajdz_c(int a, int b)
{
	
	int c = -1;

	for (int i = b; i >= a; i--)
	{
		if (tablicaSchrage[i].q < tablicaSchrage[b].q)
		{
			c = i;
			break;
		}
	}
	return c;
}

int Carlier::carlier_funkcja() 
{
	Cmax = 0;
	int numer = 0;
	int r = 0;
	int suma_p = 0;
	int q = 0;

	int r_nowe = MAX_L;
	int q_nowe = MAX_L;

	int a = 0, b = 0, c = -1;
	int U = 0, LB = 0;

	U = Schrage_bez_podzialu();

	if (U < UB)
		UB = U;

	b = Znajdz_b();
	a = Znajdz_a(b);	
	c = Znajdz_c(a,b);

	if (c == -1)
	{
		return UB;
	}

	numer = tablicaSchrage[c].numer_zadania;

	int nowa_suma = 0;

	for (int i = c + 1; i <= b; i++)
	{
		if(r_nowe>tablicaSchrage[i].r)
			r_nowe = tablicaSchrage[i].r;

		suma_p += tablicaSchrage[i].p;
		nowa_suma += tablicaSchrage[i].p;

	if(q_nowe>tablicaSchrage[i].q)
		q_nowe = tablicaSchrage[i].q;
	}
	r = tablicaSchrage[c].r;
	q = tablicaSchrage[c].q;

	if(tablicaSchrage[c].r<r_nowe+suma_p)
		tablicaSchrage[c].r = r_nowe + suma_p;

	LB = Schrage_z_podzialem();

	if (LB < UB)
	{
		carlier_funkcja();
	}


	for (int i = 0; i < liczba_zadan; i++)
	{
		if (numer == tablicaSchrage[i].numer_zadania)
		{
			tablicaSchrage[i].r = r;
		}
	}

	if (tablicaSchrage[c].q < q_nowe + suma_p)
		tablicaSchrage[c].q = q_nowe + suma_p;


	LB = Schrage_z_podzialem();

	if (LB < UB)
	{
		carlier_funkcja();
	}

	for (int i = 0; i < liczba_zadan; i++)
	{
		if (numer == tablicaSchrage[i].numer_zadania)
		{
			tablicaSchrage[i].q = q;
		}
	}
	return UB;
}
