#include "../inc/Statystyki.hh"

Statystyka::Statystyka()
{
    this->poprawne = 0;
    this->niepoprawne = 0;
}

void Statystyka::Wyswietl()
{
    std::cout << std::endl;
    std::cout << "Ilosc dobrych  odpowiedzi: " << this->poprawne << std::endl;
    std::cout << "Ilosc blednych odpowiedzi: " << this->niepoprawne << std::endl;
    if(this->poprawne + this->niepoprawne)       // Sprawdzanie, czy obliczenie statystyki jest możliwe - zabezpieczenie przed dzieleniem przez 0
        std::cout << "Wynik procentowy poprawnych odpowiedzi: " << (this->poprawne * 100) / (this->poprawne + this->niepoprawne) << "%" << std::endl;
    std::cout << std::endl;
}
