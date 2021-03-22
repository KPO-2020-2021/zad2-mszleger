#ifndef BAZATESTU_HH
#define BAZATESTU_HH

#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "WyrazenieZesp.hh"

/*
 * Struktura reprezentująca zestaw pytań do testu.
 * Zawiera wskaźnik na plik, z którego mają zostać pobrane pytanie testowe.
 */
struct BazaTestu {
  // Wskaźnik na otworzony plik
  std::fstream openedFile;

  /**
   * Destruktor sprawdza czy plik został uprzednio otworzony, jeśli tak to destruktor go zamyka.
  **/
  ~BazaTestu();

  /*
  * Otwiera plik o danej nazwie z zadaniami testowymi.
  * Zwraca: true - udało się otworzyć plik / false - nie udało się otworzyć pliku
  */
  bool InicjalizujTest(std::string nazwaPliku);

  /*
  * Udostepnia nastepne pytanie z pliku.
  * Zwraca: true - zwrócono nowe pytanie / false - koniec plików
  */
  bool PobierzNastpnePytanie(WyrazenieZesp *wskWyr);
};

#endif
