#include "../inc/main.hh"

/**
 * Kody błędów:
 * 1-dzielenie przez 0
 * 2-niewłaściwy kod operacji
**/

int main(int argc, char **argv)
{
  // Inicjowanie zmiennych
  WyrazenieZesp   WyrZ_PytanieTestowe;
  Statystyka statystyka;
  LZespolona Odpowiedz;
  LZespolona liczbaPomocnicza(1, 1);
  int invalidInputAmount = 0;


  // Sprawdzanie czy podano argument określający poziom trudności testu
  if (argc < 2)
  {
    std::cout << std::endl;
    std::cout << " Brak opcji okreslajacej rodzaj testu." << std::endl;
    std::cout << " Dopuszczalne nazwy to:  latwy, trudny." << std::endl;
    std::cout << std::endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    std::cerr << " Inicjalizacja testu nie powiodla sie." << std::endl;
    return 1;
  }

  // Pobieranie wyrażeń z zestawu testowego i zadawanie pytań użytkownikowi  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe))
  {
    std::cout << std::endl;
    std::cout << ":? Podaj wynik operacji:  ";
    std::cout << WyrZ_PytanieTestowe << " =";
    std::cout << std::endl;
    // Pobieranie odpowiedzi od użytkownika - 3 szanse na wprowadzenie poprawnej odpowiedzi
    while(true)
    {
      std::cout << "   Twoja odpowiedź: ";
      std::cin  >> Odpowiedz;
      // Obsługa błędu
      if(std::cin.fail())
      {
        // Kasowanie flagi błędu
        std::cin.clear();
        // Wywoływanie błędnej odpowiedzi jeśli trzeci raz podno odpowiedź w niepoprawnej formie
        if(invalidInputAmount == 2)
        {
          Odpowiedz = WyrZ_PytanieTestowe.Oblicz() + liczbaPomocnicza;
          invalidInputAmount = 0;
          break;
        }
        // Wyświetlanie informacji o błędzie
        std::cout << std::endl;
        std::cout << "   Blad zapisu liczby zespolonej. Sprobuj jeszcze raz.";
        std::cout << std::endl << std::endl;
        invalidInputAmount += 1;
      }else{
        invalidInputAmount = 0;
        break;
      }
    }
    // Sprawdzanie poprawności odpowiedzi
    if(Odpowiedz == WyrZ_PytanieTestowe.Oblicz())
    {
      std::cout << ":) Odpowiedz poprawna";
      std::cout << std::endl;
      statystyka.poprawne += 1;
    }else{
      std::cout << ":( Blad. Prawidlowym wynikiem jest: ";
      std::cout << WyrZ_PytanieTestowe.Oblicz();
      std::cout << std::endl;
      statystyka.niepoprawne += 1;
    }
  }
  // Wyświetlanie informacji o końcu testu
  std::cout << std::endl;
  std::cout << " Koniec testu.";
  std::cout << std::endl;
  // Wyświetlanie statystyki testu
  statystyka.Wyswietl();
}
