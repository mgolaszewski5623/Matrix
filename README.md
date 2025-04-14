# Matrix Library in C++

## Opis

Ten projekt to implementacja klasy `Matrix` w języku C++ wraz z zestawem testów jednostkowych.

Klasa `Matrix` obsługuje operacje na macierzach, takie jak dodawanie, odejmowanie, mnożenie (zarówno przez inną macierz, jak i przez skalar), transpozycja, ślad oraz porównania. 


## Funkcjonalności klasy `Matrix`

- Konstrukcja macierzy:
  - Domyślna (1x1)
  - Kwadratowa `Matrix(n)`
  - Prostokątna `Matrix(y, x)`
  - Kopiująca
- Dostęp do wymiarów i elementów: `GetX()`, `GetY()`, `Get(y, x)`
- Operatory:
  - `+`, `-`, `*` (macierz i skalar)
  - `=`, `+=`, `-=`, `*=`
  - `==`, `!=`
- Metody:
  - `Transposition()`
  - `Trace()` (tylko dla macierzy kwadratowych)
- Obsługa wyjątków przy nieprawidłowych rozmiarach

---

## Uruchamianie testów

1. Otwórz projekt w **Visual Studio**.
2. Zbuduj rozwiązanie.
3. W menu **Test > Uruchom wszystkie testy** — testy powinny się pojawić i zostać wykonane.

---

## Wymagania

- Visual Studio 2019 / 2022
- Framework testowy MSTest (zazwyczaj domyślnie dostępny)
- Kompilator C++ (MSVC)

---
