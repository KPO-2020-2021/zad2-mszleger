#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH

#include "LZespolona.hh"

/*
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };

/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego

  /**
   * Metoda zwraca wartość wyrażenia zespolonego
  **/
  const LZespolona Oblicz();
};

/*
 * Przeciążenie operatora strumienia wyjściowego <<
 */
std::ostream & operator << (std::ostream & s, const WyrazenieZesp WyrZ);

/*
 * Przeciążenie operatora strumienia wejściowego >>
 */
std::istream & operator >> (std::istream & is, WyrazenieZesp & WyrZ);

#endif
