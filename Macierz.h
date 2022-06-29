#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "Interface.h"

class Macierz : protected Interface
{
private:
	std::vector <double> elementy;
	int x = 0; //liczba kolumn
	int y = 0; //liczba wierszy
public:
	void show();	///Wyswietla wektor w konsoli komputera.
	void usun();	///Usuwa wszystkie elementy wektora oraz zmienia rozmiar na 0 kolumn i 0 wierszy.
	int size_x() { return x; }	//Zwraca rozmiar macierzy we wspolrzednej x. Liczba kolumn.
	int size_y() { return y; }	//Zwraca rozmiar macierzy we wspolrzednej y. Liczba wierszy.
	void size_set(int x, int y);	//Ustawianie wielkosci macierzy. x-kolumny, y-wiersze.
	Macierz operator +(Macierz Mac);	//Przeciazenie operatora + do dodawania macierzy
	Macierz operator -(Macierz Mac);	//Przeciazenie operatora - do odejmowania macierzy
	Macierz operator *(Macierz Mac);	//Przeciazenie operatora * do mnozenia dwoch macierzy
	Macierz operator *(double liczba);	//Przeciazenie przeciazenia operatora * do mnozenia macierzy przez liczbe.
	Macierz transponowanie();		//Transponowanie macierzy
	Macierz dopelnienie();
	double wyznacznik(int rozmiar, std::vector<std::vector<double>> tablica_2d);		//Zwraca obliczony wyznacznik.
	std::vector <std::vector<double>> stereo();											//Zwraca tablice dwuwymiarowa.
	int znak_mac(int x);	//Funkcja potrzebna do wynacznika macierzy (potegowanie liczby -1)

	template <typename T>
	void zapis(std::vector <T> elementy)	//Dostajac wektor, w ktorym ostatnie dwie liczby to jego wielkosc. Przeksztalca na Macierz.
	{
		x = elementy.back();	//liczba kolumn.
		elementy.pop_back();
		y = elementy.back();	//liczba wierszy.
		elementy.pop_back();
		for (int i = 0; i < elementy.size(); i++)
		{
			this->elementy.push_back(elementy[i]);
		}
	}
};