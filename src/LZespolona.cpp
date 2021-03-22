#include "../inc/LZespolona.hh"

LZespolona  operator + (LZespolona  liczba1,  LZespolona  liczba2)
{
  liczba1.re += liczba2.re;
  liczba1.im += liczba2.im;
  return liczba1;
}

LZespolona  operator - (LZespolona  liczba1,  LZespolona  liczba2)
{
  liczba1.re -= liczba2.re;
  liczba1.im -= liczba2.im;
  return liczba1;
}

LZespolona  operator * (LZespolona  liczba1,  LZespolona  liczba2)
{
  LZespolona wynik;
  wynik.re = (liczba1.re*liczba2.re)-(liczba1.im*liczba2.im);
  wynik.im = (liczba1.re*liczba2.im)+(liczba1.im*liczba2.re);
  return wynik;
}

LZespolona  operator * (LZespolona  liczba1,  double  liczba2)
{
  liczba1.re *= liczba2;
  liczba1.im *= liczba2;
  return liczba1;
}

LZespolona operator * (double liczba1, LZespolona liczba2)
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

LZespolona  operator / (LZespolona  liczba1,  double  liczba2)
{
  if(liczba2 == 0)
    throw (1);
  liczba1.re /= liczba2;
  liczba1.im /= liczba2;
  return liczba1;
}

bool operator == (LZespolona  liczba1,  LZespolona  liczba2)
{
  // Porównywanie zaokrąglonych liczb
  if(round(liczba1.re * pow(10, PRECISION)) != round(liczba2.re * pow(10, PRECISION)))
    return false;
  if(round(liczba1.im * pow(10, PRECISION)) != round(liczba2.im * pow(10, PRECISION)))
    return false;
  return true;
}

bool operator != (LZespolona  liczba1,  LZespolona  liczba2)
{
  return !(liczba1 == liczba2);
}

std::ostream & operator << ( std::ostream & s, LZespolona liczba)
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
  char nawias, litera;
  // Pobieranie nawiasu
  is >> nawias;
  if(is.fail())
    return is;
  if(nawias != '(')
  {
    is.setstate(std::ios::failbit);
    return is;
  }
  // Pobieranie części rzeczywistej
  is >> liczba.re;
  if(liczba.re == 0)
    liczba.re = 0;
  if(is.fail())
    return is;
  // Pobieranie części urojonej
  is >> liczba.im;
  if(liczba.im == 0)
    liczba.im = 0;
  if(is.fail())
    return is;
  // Pobieranie litery 'i'
  is >> litera;
  if(is.fail())
    return is;
  if(litera != 'i')
  {
    is.setstate(std::ios::failbit);
    return is;
  }
  // Pobieranie nawiasu
  is >> nawias;
  if(is.fail())
    return is;
  if(nawias != ')')
  {
    is.setstate(std::ios::failbit);
    return is;
  }
  return is;
}

LZespolona::LZespolona()
{
  this->re = 0;
  this->im = 0;
}

LZespolona::LZespolona(double reValue, double imValue)
{
  this->re = reValue;
  this->im = imValue;
}

LZespolona LZespolona::Sprzezenie()
{
  LZespolona liczba;
  liczba.re = this->re;
  if(this->im != 0)                             // Zabezpieczenie się przed ustawieniem wartości części urojonej na -0
    liczba.im = -this->im;
  else
    liczba.im = 0;
  return liczba;
}

double LZespolona::Modul2()
{
  return (this->re*this->re) + (this->im*this->im);
}