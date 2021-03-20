#include "../inc/WyrazenieZesp.hh"

std::ostream & operator << (std::ostream & s, WyrazenieZesp WyrZ)
{
    char znaki[] = {'+', '-', '*', '/'};
    return s << WyrZ.Arg1 << " " << znaki[WyrZ.Op] << " " << WyrZ.Arg2;
}

std::istream & operator >> (std::istream & is, WyrazenieZesp & WyrZ)
{
    char znak;
    // Wczytywanie pierwszego argumentu
    is >> WyrZ.Arg1;
    if(is.fail())
        return is;
    // Wczytanie znaku operacji
    is >> znak;
    if(is.fail())
        return is;
    if(znak == '+')
        WyrZ.Op = Op_Dodaj;
    else if(znak == '-')
        WyrZ.Op = Op_Odejmij;
    else if(znak == '*')
        WyrZ.Op = Op_Mnoz;
    else if(znak == '/')
        WyrZ.Op = Op_Dziel;
    else {
        is.setstate(std::ios::failbit);
        return is;
    }
    // Wczytywanie drugiego argumentu
    is >> WyrZ.Arg2;
    if(is.fail())
        return is;
    return is;
}

LZespolona WyrazenieZesp::Oblicz()
{
    // Obsługiwanie operacji dodawania
    if(this->Op == 0)
        return this->Arg1 + this->Arg2;
    // Obsługiwanie operacji minus
    if(this->Op == 1)
        return this->Arg1 - this->Arg2;
    // Obsługiwanie operacji mnożenia
    if(this->Op == 2)
        return this->Arg1 * this->Arg2;
    // Obsługiwanie operacji dzielenia
    if(this->Op == 3)
        return this->Arg1 / this->Arg2;
    throw (2);
}









