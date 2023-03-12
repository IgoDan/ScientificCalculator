#include <iostream>
#include <string>
#include "Operations.h"
#include <cmath>

int main() {
    std::cout << "Dziala dzialanie z minusem za znakiem, np: -2--2 = 0. Aby wyjsc wpisz E" << std::endl;
    std::cout << std::endl;

    Operations obl;

    while (true) {

        int id_prio = 1;
        int id_liczb = 0;
        int id_znakow = 0;
        int j = 0, k = 0;
        int ktora_cyfra = 0;  //na ktorym miejscu w kolejnosci w dzialaniu stoi liczba
        int dl_dzialanie = 0; //ilosc komponentow skladajacych sie na dzialanie
        int flaga_minus = 0;

        std::cout << "Wpisz dzialanie:   ";
        std::cin >> obl.input;

        if (obl.input[0] == 'E') {
            break;
        }
        //Zerowanie tablic
        for (int i = 0; i < 100; i++) {
            obl.liczba[i] = 0;
            obl.znak[i] = "";
            obl.tab_temp[i] = "";
            obl.dzialanie[i] = "";
        }
        //Tabica ze stringami input -> dzialanie, aby odzdzielić liczby od znaków
        while (obl.input[j] != '\0') {
            //gdy zero na poczatku
            if (j == 0 && obl.input[j] == '-') {
                flaga_minus = 1;
                j += 1;
                continue;
            }
            if (obl.input[j] == '^' || obl.input[j] == 'p' || obl.input[j] == '%' || obl.input[j] == '*' || obl.input[j] == '/' ||
                obl.input[j] == '+' || obl.input[j] == '-') {
                if (obl.input[j + 1] == '-') {
                    obl.dzialanie[k] = obl.input[j];
                    j += 2;
                    k += 1;
                    continue;
                }
                obl.dzialanie[k] = obl.input[j];
                k += 1;
                j += 1;
                continue;
            }
            if (isdigit(obl.input[j]) || obl.input[j] == '.') {
                if ((j >= 2 && obl.input[j - 1] == '-' && isdigit(obl.input[j - 2]) == 0) || (flaga_minus == 1 && j == 1))
                    obl.temp = "-";
                else
                    obl.temp = "";
                while (isdigit(obl.input[j]) || obl.input[j] == '.') {
                    obl.temp += obl.input[j];
                    j += 1;
                }
                obl.dzialanie[k] = obl.temp;
                k += 1;
                continue;
            }
            flaga_minus = 0;
        }

        dl_dzialanie = k;

        if (obl.dzialanie[1] == "") {
            std::cout << obl.dzialanie[0] << std::endl;
            continue;
        }

        int i = 0;
        int b = 0;
        int spr = 0;
        int akt = 0;
        int flaga_blad = 0;
        while (obl.dzialanie[i] != "") {
            if (obl.dzialanie[i] == "^" || obl.dzialanie[i] == "p" || obl.dzialanie[i] == "%") {
                akt = 0;
                spr = i;
                b = 0;
                //Dodanie przed wynik
                while (b < spr - 1) {
                    obl.tab_temp[b] = obl.dzialanie[b];
                    akt++;
                    b++;
                }
                obl.a = std::stod(obl.dzialanie[spr - 1]);
                obl.b = std::stod(obl.dzialanie[spr + 1]);
                switch (obl.dzialanie[spr][0]) {
                case('^'): obl.potega(); break;
                case('p'): if (obl.a < 0) { flaga_blad = 1; break; } obl.pierwiastek(); break;
                case('%'): obl.procent(); break;
                }
                if (flaga_blad == 1)
                    break;
                //Dodanie wyniku
                obl.tab_temp[akt] = std::to_string(obl.wynik);
                b++; akt++;
                //Dodanie za wynik
                b = spr + 2;
                while (obl.dzialanie[b] != "") {
                    obl.tab_temp[akt] = obl.dzialanie[b];
                    akt++;
                    b++;
                }
                k = 0;
                //Przepisanie tablicy temp z powrotem do tablicy dzialanie
                while (obl.dzialanie[k] != "") {
                    obl.dzialanie[k] = obl.tab_temp[k];
                    obl.tab_temp[k] = "";
                    k++;
                }
                i = 0;
                continue;
            }
            else {
                i++;
                continue;
            }
        }

        i = 0;
        b = 0;
        spr = 0;
        akt = 0;
        while (obl.dzialanie[i] != "") {
            if (obl.dzialanie[i] == "*" || obl.dzialanie[i] == "/") {
                akt = 0;
                spr = i;
                b = 0;
                //Dodanie przed wynik
                while (b < spr - 1) {
                    obl.tab_temp[b] = obl.dzialanie[b];
                    akt++;
                    b++;
                }
                obl.a = std::stod(obl.dzialanie[spr - 1]);
                obl.b = std::stod(obl.dzialanie[spr + 1]);
                switch (obl.dzialanie[spr][0]) {
                case('*'): obl.mnozenie(); break;
                case('/'): if (obl.b == 0) { flaga_blad = 1; break; } obl.dzielenie(); break;
                }
                if (flaga_blad == 1)
                    break;
                //Dodanie wyniku
                obl.tab_temp[akt] = std::to_string(obl.wynik);
                b++; akt++;
                //Dodanie za wynik
                b = spr + 2;
                while (obl.dzialanie[b] != "") {
                    obl.tab_temp[akt] = obl.dzialanie[b];
                    akt++;
                    b++;
                }
                k = 0;
                //Przepisanie tablicy temp z powrotem do tablicy dzialanie
                while (obl.dzialanie[k] != "") {
                    obl.dzialanie[k] = obl.tab_temp[k];
                    obl.tab_temp[k] = "";
                    k++;
                }
                i = 0;
                continue;
            }
            else {
                i++;
                continue;
            }
        }

        i = 0;
        b = 0;
        spr = 0;
        akt = 0;
        while (obl.dzialanie[i] != "") {
            if (obl.dzialanie[i] == "+" || obl.dzialanie[i] == "-") {
                akt = 0;
                spr = i;
                b = 0;
                //Dodanie przed wynik
                while (b < spr - 1) {
                    obl.tab_temp[b] = obl.dzialanie[b];
                    akt++;
                    b++;
                }
                obl.a = std::stod(obl.dzialanie[spr - 1]);
                obl.b = std::stod(obl.dzialanie[spr + 1]);
                switch (obl.dzialanie[spr][0]) {
                case('+'): obl.dodawanie(); break;
                case('-'): obl.odejmowanie(); break;
                }
                if (flaga_blad == 1) {
                    break;
                }
                //Dodanie wyniku
                obl.tab_temp[akt] = std::to_string(obl.wynik);
                b++; akt++;
                //Dodanie za wynik
                b = spr + 2;
                while (obl.dzialanie[b] != "") {
                    obl.tab_temp[akt] = obl.dzialanie[b];
                    akt++;
                    b++;
                }
                k = 0;
                //Przepisanie tablicy temp z powrotem do tablicy dzialanie
                while (obl.dzialanie[k] != "") {
                    obl.dzialanie[k] = obl.tab_temp[k];
                    obl.tab_temp[k] = "";
                    k++;
                }
                i = 0;
                continue;
            }
            else {
                i++;
                continue;
            }
        }
        if (flaga_blad == 1) {
            std::cout << "Bledne dane do pierwiastka/dzielenia" << std::endl;
            continue;
        }

        std::cout << obl.wynik << std::endl;
    }
    return 0;
}
