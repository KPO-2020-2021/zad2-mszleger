#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "../inc/LZespolona.hh"

TEST_CASE("test LZespolona Porównanie 1"){
    LZespolona x, y;

    x.re = 1;
    x.im = 2;

    y.re = 1;
    y.im = 2;

    CHECK(x == y);
}

TEST_CASE("test LZespolona Porównanie 2"){
    LZespolona x, y;

    x.re = 2;
    x.im = 1;

    y.re = 3;
    y.im = 1;

    CHECK_FALSE(x == y);
}

TEST_CASE("test LZespolona Porównanie 3"){
    LZespolona x, y;

    x.re = 1;
    x.im = 2;

    y.re = 1;
    y.im = 3;

    CHECK_FALSE(x == y);
}

TEST_CASE("test LZespolona Porównanie 4"){
    LZespolona x, y;

    x.re = 1;
    x.im = 2;

    y.re = 1;
    y.im = 2;

    CHECK_FALSE(x != y);
}

TEST_CASE("test LZespolona Porównanie 5"){
    LZespolona x, y;

    x.re = 2;
    x.im = 1;

    y.re = 3;
    y.im = 1;

    CHECK(x != y);
}

TEST_CASE("test LZespolona Porównanie 6"){
    LZespolona x, y;

    x.re = 1;
    x.im = 2;

    y.re = 1;
    y.im = 3;

    CHECK(x != y);
}

TEST_CASE("test LZespolona Porównanie 7"){
    LZespolona x, y;

    x.re = 1.66666666;
    x.im = 2.66666666;

    y.re = 1.67;
    y.im = 2.67;

    CHECK(x == y);
}

TEST_CASE("test LZespolona Porównanie 8"){
    LZespolona x, y;

    x.re = 1.66666666;
    x.im = 2.66666666;

    y.re = 1.666;
    y.im = 2.666;

    CHECK(x == y);
}

TEST_CASE("test LZespolona Dodawanie"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 2;

    y.re = 1;
    y.im = 3;

    z.re = 2;
    z.im = 5;

    CHECK((x + y) == z);
}

TEST_CASE("test LZespolona Odejmowanie"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = 2;

    y.re = 1;
    y.im = 3;

    z.re = 0;
    z.im = -1;

    CHECK((x - y) == z);
}

TEST_CASE("test LZespolona Mnożenie przez skalar 1"){
    LZespolona x, z;
    double y;

    x.re = 1;
    x.im = 2;

    y = 4;

    z.re = 4;
    z.im = 8;

    CHECK((x * y) == z);
}

TEST_CASE("test LZespolona Mnożenie przez skalar 2"){
    LZespolona x, z;
    double y;

    x.re = 1;
    x.im = 2;

    y = 4;

    z.re = 4;
    z.im = 8;

    CHECK((y * x) == z);
}

TEST_CASE("test LZespolona Mnożenie dwóch liczb zespolonych"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = -2;

    y.re = 3;
    y.im = 4;

    z.re = 11;
    z.im = -2;

    CHECK((x * y) == z);
}

TEST_CASE("test LZespolona Dzielenie przez skalar"){
    LZespolona x, z;
    double y;

    x.re = 12;
    x.im = -9;

    y = 3;

    z.re = 4;
    z.im = -3;

    CHECK((x / y) == z);
}

TEST_CASE("test LZespolona Dzielenie dwóch liczb zespolonych"){
    LZespolona x, y, z;

    x.re = 1;
    x.im = -2;

    y.re = 3;
    y.im = 4;

    z.re = -0.2;
    z.im = -0.4;

    CHECK((x / y) == z);
}

TEST_CASE("test LZespolona Moduł2"){
    LZespolona x;
    double z;

    x.re = 3;
    x.im = -2;

    z = 13;

    CHECK(x.Modul2() == z);
}

TEST_CASE("test LZespolona Sprzężenie"){
    LZespolona x, z;

    x.re = 1;
    x.im = -2;

    z.re = 1;
    z.im = 2;

    CHECK(x.Sprzezenie() == z);
}