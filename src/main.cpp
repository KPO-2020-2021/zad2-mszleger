#include "../inc/main.hh"

/**
 * Kody błędów:
 * 1-dzielenie przez 0
 * 2-niewłaściwy kod operacji
 * 3-nie można otworzyć pliku, ponieważ inny plik został uprzednio otwarty
**/

int main(int argc, char **argv)
{
  // Inicjowanie zmiennych
  WyrazenieZesp WyrZ_PytanieTestowe;   // Zmienna przechowująca zadanie testowe
  Statystyka statystyka;               // Zmienna przechowująca statystykę testu
  LZespolona Odpowiedz;                // Zmienna przechowująca odpowiedź użytkownika na zadanie testowe
  LZespolona liczbaPomocnicza(1, 1);   // Zmienna przechowująca liczbę zespoloną służącą do symulowania niepoprawnych odpowiedzi
  BazaTestu BazaT;                     // Zmienna przechowująca zadania testowe
  int invalidInputAmount = 0;          // Zmienna przechowująca ilość wprowadzeń liczby zespolonej w nieodpowiednim formacie

  // Sprawdzanie czy podano argument określający nazwę pliku z zadaniami do testu
  if (argc < 2)
  {
    std::cerr << std::endl;
    std::cerr << "  Brak opcji okreslajacej nazwę pliku z zadaniami do testu." << std::endl;
    std::cerr << std::endl;
    return 1;
  }

  // Inicjowanie testu
  if (BazaT.InicjalizujTest(argv[1]) == false)
  {
    std::cerr << "  Inicjalizacja testu nie powiodla sie. Nie udało się otworzyć pliku o podanej nazwie." << std::endl;
    return 1;
  }

  // Pobieranie wyrażeń z zestawu testowego i zadawanie pytań użytkownikowi  
  while (BazaT.PobierzNastpnePytanie(&WyrZ_PytanieTestowe))
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
        // Opróżnianie bufora wejściowego
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
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
