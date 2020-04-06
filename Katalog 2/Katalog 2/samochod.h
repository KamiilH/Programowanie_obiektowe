#ifndef SAMOCHOD_H
#define SAMOCHOD_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
using namespace std;

class samochod
{
	string marka, model;
	short int rocznik, moc;
	float pojemnosc;
	int przebieg;
	bool skrzynia; //0-manual, 1-automat
public:

};

samochod* wczytaj(int* i);
void zapisz(int i, samochod kat[]);
samochod* dodaj(int* i, samochod kat[]);
samochod* powieksz(int i, samochod kat[]);
istream& operator>> (istream& wejscie, samochod& s);
samochod* usun(int* i, samochod kat[]);
samochod* zmniejsz(int* i, samochod kat[]);
//////////////////////////////////////////////
void wypis_wszystkich(int i, samochod kat[]);
void po_parametrach(int i, samochod kat[]);
void posortowane(int i, samochod kat[]);
void swap(samochod tablica[], int i, int j);
void quick_sort(samochod tab[], int lewy, int prawy, int par);
#endif
