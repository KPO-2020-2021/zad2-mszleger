#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "../inc/WyrazenieZesp.hh"

TEST_CASE("test WyrazenieZespolone Obliczanie sumy"){
    WyrazenieZesp x;
    LZespolona z;

    x.Arg1.re = 3;
    x.Arg1.im = 5;

    x.Op = Op_Dodaj;

    x.Arg2.re = 7;
    x.Arg2.im = 4;

    z.re = 10;
    z.im = 9;
    
    CHECK(x.Oblicz() == z);
}

TEST_CASE("test WyrazenieZespolone Obliczanie różnicy"){
    WyrazenieZesp x;
    LZespolona z;

    x.Arg1.re = 3;
    x.Arg1.im = 5;

    x.Op = Op_Odejmij;

    x.Arg2.re = 7;
    x.Arg2.im = 4;

    z.re = -4;
    z.im = 1;
    
    CHECK(x.Oblicz() == z);
}

TEST_CASE("test WyrazenieZespolone Obliczanie iloczynu"){
    WyrazenieZesp x;
    LZespolona z;

    x.Arg1.re = 12;
    x.Arg1.im = 3;

    x.Op = Op_Mnoz;

    x.Arg2.re = 6;
    x.Arg2.im = 3;

    z.re = 63;
    z.im = 54;
    
    CHECK(x.Oblicz() == z);
}

TEST_CASE("test WyrazenieZespolone Obliczanie ilorazu"){
    WyrazenieZesp x;
    LZespolona z;

    x.Arg1.re = 12;
    x.Arg1.im = 3;

    x.Op = Op_Dziel;

    x.Arg2.re = 6;
    x.Arg2.im = 3;

    z.re = 1.8;
    z.im = -0.4;
    
    CHECK(x.Oblicz() == z);
}