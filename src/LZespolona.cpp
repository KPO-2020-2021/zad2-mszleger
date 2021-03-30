#include "../inc/LZespolona.hh"

LZespolona  operator + (const LZespolona  liczba1,  const LZespolona  liczba2)
{
  LZespolona liczba;
  liczba.re = liczba1.re + liczba2.re;
  liczba.im = liczba1.im + liczba2.im;
  return liczba;
}

LZespolona  operator - (const LZespolona  liczba1,  const LZespolona  liczba2)
{
  LZespolona liczba;
  liczba.re = liczba1.re - liczba2.re;
  liczba.im = liczba1.im - liczba2.im;
  return liczba;
}

LZespolona  operator * (const LZespolona  liczba1,  const LZespolona  liczba2)
{
  LZespolona wynik;
  wynik.re = (liczba1.re*liczba2.re)-(liczba1.im*liczba2.im);
  wynik.im = (liczba1.re*liczba2.im)+(liczba1.im*liczba2.re);
  return wynik;
}

LZespolona  operator * (const LZespolona  liczba1,  const double  liczba2)
{
  LZespolona liczba;
  liczba.re = liczba1.re * liczba2;
  liczba.im = liczba1.im * liczba2;
  return liczba;
}

LZespolona operator * (const double liczba1, const LZespolona liczba2)
{
  return liczba2 * liczba1;
}

LZespolona  operator / (LZespolona  liczba1,  LZespolona  liczba2)
{
  double modul2 = liczba2.Modul2();
  if(modul2 == 0)
    throw (1);
  return (liczba1 * liczba2.Sprzezenie()) / modul2;
}

LZespolona  operator / (const LZespolona  liczba1,  const double  liczba2)
{
  LZespolona liczba;
  if(liczba2 == 0)
    throw (1);
  liczba.re = liczba1.re / liczba2;
  liczba.im = liczba1.im / liczba2;
  return liczba;
}

bool operator == (const LZespolona  liczba1,  const LZespolona  liczba2)
{
  // Porównywanie zaokrąglonych liczb
  if(round(liczba1.re * pow(10, PRECISION)) != round(liczba2.re * pow(10, PRECISION)))
    return false;
  if(round(liczba1.im * pow(10, PRECISION)) != round(liczba2.im * pow(10, PRECISION)))
    return false;
  return true;
}

bool operator != (const LZespolona  liczba1,  const LZespolona  liczba2)
{
  return !(liczba1 == liczba2);
}

std::ostream & operator << (std::ostream & s, const LZespolona liczba)
{
  // Wyświetlanie części rzeczywistej
  if(liczba.re == 0)
    s << "(0";
  else
    s << "(" << liczba.re;
  // Wyświetlanie części urojonej
  if(liczba.im > 0)
    return s << "+" << liczba.im << "i)";
  if(liczba.im == 0)
    return s  << "+0i)";
  return s << liczba.im << "i)";
}

std::istream & operator >> (std::istream& is, LZespolona& liczba)
{
  char znak, peek1, peek2;
  double liczba1, liczba2;
  bool odczyt1 = false, odczyt2 = false;

  // Pobieranie nawiasu
  is >> znak;
  if(is.fail())
    return is;
  if(znak != '(')
  {
    is.setstate(std::ios::failbit);
    return is;
  }

  // Zapisywanie następnego znaku
  peek1 = is.peek();
  // Wczytywanie liczby nr. 1
  is >> liczba1;
  // Sprawdzanie czy udało się wczytać liczbę
  if(is.fail() == false)
  {
    odczyt1 = true;
    // Zapisywanie następnego znaku
    peek2 = is.peek();
    // Wczytywanie liczby nr. 2
    is >> liczba2;
    // Sprawdzanie czy udało się wczytać liczbę
    if(is.fail() == false)
    {
      odczyt2 = true;
    }
  }
  // Czyszczenie flagi błędu jeśli jest ustawiona
  if(is.fail())
    is.clear();

  // Wczytywanie znaku
  is >> znak;

  // Zwracanie błędu jeśli nie udało się wczytać znaku
  if(is.fail())
    return is;

  // Sprawdzanie czy wczytany znak to 'i'
  if(znak == 'i')
  {
    // Wczytany znak to 'i'
    // Sprawdzanie czy udało się wczytać obie liczby
    if(odczyt1 && odczyt2)
    {
      liczba.re = liczba1;
      liczba.im = liczba2;
    }else{
      // Sprawdzanie czy udało się wczytać pierwszą liczbę
      if(odczyt1)
      {
        // Sprawdzanie czy podjerzany znak to '+'
        if(peek2 == '+')
        {
          liczba.re = liczba1;
          liczba.im = 1;
        // Sprawdzanie czy podjerzany znak to '-'
        }else if(peek2 == '-')
        {
          liczba.re = liczba1;
          liczba.im = -1;
        // Sprawdzanie czy podjerzany znak to 'i'
        }else if(peek2 == 'i')
        {
          liczba.re = 0;
          liczba.im = liczba1;
        }else{
          // Zwracanie błędu jeśli nie rozpoznano znaku
          is.setstate(std::ios::failbit);
          return is;
        }
      }else{
        // Sprawdzanie czy podjerzany znak to '+'
        if(peek1 == '+')
        {
          liczba.re = 0;
          liczba.im = 1;
        // Sprawdzanie czy podjerzany znak to '-'
        }else if(peek1 == '-')
        {
          liczba.re = 0;
          liczba.im = -1;
        // Sprawdzanie czy podjerzany znak to 'i'
        }else if(peek1 == 'i')
        {
          liczba.re = 0;
          liczba.im = 1;
        }else{
          // Zwracanie błędu jeśli nie rozpoznano znaku
          is.setstate(std::ios::failbit);
          return is;
        }
      }
    }
    // Wczytywanie znaku
    is >> znak;
    // Zwracanie błędu jeśli nie udało się wczytać znaku
    if(is.fail())
      return is;
  }else{
    // Wczytany znak to nie 'i'
    // Sprawdzanie czy udało się wczytać obie liczby
    if(odczyt1 && odczyt2)
    {
      // Zwracanie błędu
      is.setstate(std::ios::failbit);
      return is;
    }else{
      // Sprawdzanie czy udało się wczytać pierwszą liczbę
      if(odczyt1)
      {
        liczba.re = liczba1;
        liczba.im = 0;
      }else{
      // Zwracanie błędu
      is.setstate(std::ios::failbit);
      return is; 
      }
    }
  }

  // Sprawdzanie czy wczytano nawias
  if(znak != ')')
  {
    is.setstate(std::ios::failbit);
    return is;
  }
  // Poprawne kończenie pracy funkcji
  return is;
}

LZespolona::LZespolona()
{
  this->re = 0;
  this->im = 0;
}

LZespolona::LZespolona(const double reValue, const double imValue)
{
  this->re = reValue;
  this->im = imValue;
}

const LZespolona LZespolona::Sprzezenie()
{
  LZespolona liczba;
  liczba.re = this->re;
  if(this->im != 0)                             // Zabezpieczenie się przed ustawieniem wartości części urojonej na -0
    liczba.im = -this->im;
  else
    liczba.im = 0;
  return liczba;
}

const double LZespolona::Modul2()
{
  return (this->re*this->re) + (this->im*this->im);
}