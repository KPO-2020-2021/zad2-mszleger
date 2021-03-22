#include "../inc/BazaTestu.hh"

BazaTestu::~BazaTestu()
{
  if(this->openedFile.is_open())
    this->openedFile.close();
}

bool BazaTestu::InicjalizujTest(std::string nazwaPliku)
{
  // Sprawdzanie czy plik nie został uprzednio otworzony
  if(this->openedFile.is_open())
  {
    return false;
  }
  // Otwieranie pliku
  this->openedFile.open(nazwaPliku + ".dat");
  // Sprawdzanie czy udało się otworzyć plik
  if(this->openedFile.is_open())
    return true;
  else
    return false;
}

bool BazaTestu::PobierzNastpnePytanie(WyrazenieZesp *wskWyr)
{
  while(true)
  {
    // Pobieranie wartości wyrażenia zespolonego z pliku
    this->openedFile >> *wskWyr;
    // Sprawdzanie czy udało się poprawnie odczytać wyrażenie zespolone - jeśli tak, zwracane jest true
    if(this->openedFile.fail() == false)
    {
      // Sprawdzanie czy można obliczyć wartość wyrażenia (czy np. nie występuje dzielenie przez 0)
      try
      {
        wskWyr->Oblicz();
        return true;
      }
      catch(...){}
    }
    // Sprawdzanie czy pobrano wszystkie dane z bufora - jeśli tak, zwracane jest false
    if(this->openedFile.eof())
      return false;
    // Wypisywanie komunikatu o znalezieniu wyrażenia zespolonego w nieprawidłowym formacie
    std::cerr << "   Napotkano bledne wyrazenie. Zostalo ono pominiete." << std::endl;
    // Kasowanie flag błędów
    this->openedFile.clear();
    // Przechodzenie do następnej linii
    this->openedFile.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
  }
}
