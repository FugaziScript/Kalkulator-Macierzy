#pragma once
#include "Macierz.h"
#include "Interface.h"
#include <iostream>
#include <vector>

class Menu 
{
private:
	Macierz Mac_A;	//Macierz A
	Macierz Mac_B;	//Macierz B

	//Funkcja do wprowadzania liczb, zwraca tablice stringow (moze zmienie na double).
	std::vector <std::string> wprowadzenie();		

	//Funkcja przyjmuje wprowadzona tablice stringow oraz zwraca tablice o odpowiednich typach.
	template <typename T>
	std::vector <T> stworz(std::vector <std::string> wektor);	

	//Funkcja sprawdza, jakim typem sa wprowadzone liczby. Jezeli jakakolwiek jest zmiennoprzecinkowa, zwraca true.
	bool typ(std::vector <std::string> A);			

	//Przycisniecie przycisku ENTER, aby kontunuowac.
	void ENTER_continue();				

	//Wpisuje wynik dzialania do macierzy Mac_A lub Mac_B.
	void wpis(Macierz wynik);									
public:
	//Funkcja do otwierania calego interfejsu.
	void open();												
};