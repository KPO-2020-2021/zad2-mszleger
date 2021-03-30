# Projekt 2 - Arytmetyka liczb zespolonych

## Zadania wykonane ponad plan

Wykonałem wszystkie zadania dodatkowe:
-rozpoznawanie uproszczonego zapisu liczb zespolonych (np. (i) zamiast (0+1i)),
-wczytywanie zadań do testu z plików (aby uruchomić test zapisany w pliku należy podać nazwę pliku bez rozszerzenia .dat).

## Problematyczne fragmenty programu

Dużo czasu zajęło wykonanie mi modyfikacji przeciążenia operatora >> dla liczb zespolonych, tak aby było w stanie rozpoznawać uproszczony zapis.
Pomogło narysowanie diagramu UML (zapisanego w folderze uml w katalogu projektu) w programie dia.

## Ciekawe problemy

Podczas pisania fragmentu programu umożliwiającego danie użytkownikowi 3 szans na poprawne wpisanie liczb zespolonych zdecydowałem,
że po każdej błędnej próbie należy wyczyścić bufor wejściowy, ponieważ w przeciwnym razie pojedyńcze błędne wpisanie wartości,
może spowodować rozpoznanie przez program wielu błędnych prób wprowadzenia liczby.

## Dokładność porównywania

Dokładność porównywania można określić zmieniając wartość zmiennej symbolicznej PRECISION znajdującej się w pliku inc/LZespolona.hh.
Wartość zmiennej symbolicznej określa do ilu miejsc po przecinku ma być wykonywane porównywanie z zaokrągleniem.
Np. Wartość 2 oznacza, że liczby będą porównywane z dokładnością do części setnych po uprzednim zaokrągleniu.

## Testy

Napisałem własne testy jednostkowe, które można uruchomić wywołując komendę "make mytest".
Nie napisałem testów dla strumieni wejściowych i wyjściowych.
Nie napisałem testów dla struktury BazaTestu, ponieważ nie wiedziałem jak zasymulować odczyt pliku.

