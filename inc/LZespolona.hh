#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>
#include <cmath>

// Wartość określająca ilość liczb po przecinku, które mają być brane pod uwagę podczas porównywania
#define PRECISION 2

/**
 * Modeluje pojecie liczby zespolonej
**/
struct  LZespolona {
  double   re;    // Pole repezentuje część rzeczywistą.
  double   im;    // Pole repezentuje część urojoną.

  /**
   * Konstruktor bezargumentowy ustawiający wartości zmiennych re i im na 0
  **/
  LZespolona();

  /**
   * Konstruktor pobierający dwa argumenty, które przypisuje zmiennym re i im (w tej kolejności)
  **/
  LZespolona(double reValue, double imValue);

  /**
   * Zwraca sprzężenie podanej liczby zespolonej
  **/
  LZespolona Sprzezenie();

  /**
   * Zwraca kwadrat modułu podanej liczby zespolonej
  **/
  double Modul2();
};

/*
 * Przeciążenie operatora +: Dodawanie dwóch liczb zespolonych
 */
LZespolona operator + (LZespolona liczba1, LZespolona liczba2);

/*
 * Przeciążenie operatora -: Odejmowanie dwóch liczb zespolonych
 */
LZespolona operator - (LZespolona liczba1, LZespolona liczba2);

/*
 * Przeciążenie operatora *: Mnożenie dwóch liczb zespolonych
 */
LZespolona operator * (LZespolona liczba1, LZespolona liczba2);

/*
 * Przeciążenie operatora *: Mnożenie liczby zespolonej przez liczbę rzeczywistą
 */
LZespolona operator * (LZespolona liczba1, double liczba2);

/*
 * Przeciążenie operatora *: Mnożenie liczby rzeczywistą przez liczbę zespoloną
 */
LZespolona operator * (double liczba1, LZespolona liczba2);

/*
 * Przeciążenie operatora /: Dzielenie dwóch liczb zespolonych
 */
LZespolona operator / (LZespolona liczba1, LZespolona liczba2);

/*
 * Przeciążenie operatora /: Dzielenie liczby zespolonej przez liczbę rzeczywistą
 */
LZespolona operator / (LZespolona liczba1, double liczba2);

/*
 * Przeciążenie operatora ==: Porównanie dwóch liczb zespolonych (1 - takie same / 0 - różne)
 */
bool operator == (LZespolona liczba1, LZespolona liczba2);

/*
 * Przeciążenie operatora !=: Porównania dwóch liczb zespolonych (0 - takie same / 1 - różne)
 */
bool operator != (LZespolona liczba1, LZespolona liczba2);

/*
 * Przeciążenie operatora strumienia wyjściowego <<
 */
std::ostream & operator << (std::ostream & s, LZespolona liczba);

/*
 * Przeciążenie operatora strumienia wejściowego >>
 */
std::istream& operator >> (std::istream& is, LZespolona& liczba);

#endif
