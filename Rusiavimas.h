#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
#include <vector>
#include <fstream>
#include <sstream>
#include "Studentas.h"

using std::cout;
using std::cin;
using std::string;
using std::to_string;
using std::endl;
using std::left;
using std::setw;
using std::setfill;
using std::fixed;
using std::setprecision;
using std::vector;
using std::ofstream;


void vidurkiu_rusiavimas(vector<Studentas>& A, int kiek) {

    A.push_back(Studentas());
    Laikinas L;

    for (int i = 0; i < kiek; i++) {
        for (int j = 0; j < kiek - i - 1; j++) {
            if (A[j + 1].vidurkis > A[j].vidurkis) {
                L.pavarde = A[j].pavarde;
                L.vardas = A[j].vardas;
                L.vidurkis = A[j].vidurkis;
                L.mediana = A[j].mediana;

                A[j].pavarde = A[j + 1].pavarde;
                A[j].vardas = A[j + 1].vardas;
                A[j].vidurkis = A[j + 1].vidurkis;
                A[j].mediana = A[j + 1].mediana;

                A[j + 1].pavarde = L.pavarde;
                A[j + 1].vardas = L.vardas;
                A[j + 1].vidurkis = L.vidurkis;
                A[j + 1].mediana = L.mediana;
            }
        }
    }
}
