#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH

#include <iostream>

struct  Statystyka {
  unsigned int poprawne;
  unsigned int niepoprawne;
  /**
   * Konstruktor ustawiający wartości zmiennych na 0
  **/
 Statystyka();
  /**
   * Metoda wyświetla daną statystykę
  **/
  const void Wyswietl();
};

#endif