#include "Operations.h"
#include <string>

double Operations::dodawanie() {
    wynik = a + b;
    return wynik;
}
double Operations::odejmowanie() {
    wynik = a - b;
    return wynik;
}
double Operations::mnozenie() {
    wynik = a * b;
    return wynik;
}
double Operations::dzielenie() {
    wynik = a / b;
    return wynik;
}
double Operations::pierwiastek() {
    wynik = pow(a, 1 / b);
    return wynik;
}
double Operations::potega() {
    wynik = pow(a, b);
    return wynik;
}
double Operations::procent() {
    wynik = (b / a) * 100;
    return wynik;
}