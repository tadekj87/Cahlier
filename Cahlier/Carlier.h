#pragma once
#ifndef CARLIER_H_INCLUDED
#define CARLIER_H_INCLUDED

#define MAX_L 1000000

#include "Schrage.h"

using namespace std;

class Carlier : public Schrage
{
public:

    int UB;

    Carlier() { UB = 10000000; }
    ~Carlier(){}

    int carlier_funkcja();

    int Znajdz_a(int b);
    int Znajdz_b();
    int Znajdz_c(int a, int b);
};



#endif // CARLIER_H_INCLUDED