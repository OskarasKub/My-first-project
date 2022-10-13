#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "Studentas.h"
#include "Funkcijos.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;

void vidurkis(vector<Studentas>& A, int x);
void mediana(vector<Studentas>& A, int x);
void sugeneravimas(vector<Studentas>& A, int x);
void ivedimas(vector<Studentas>& A, int& kiek);
void nuskaitymas(vector<Studentas>& A, int& kiek);
void pavardziu_rusiavimas(vector<Studentas>& A, int kiek);
void isvedimas(vector<Studentas> A, int kiek);

int main() {

    vector<Studentas> A;
    int kiek;

    string x; //Ar vedimas ranka ar is failo
    cout << "\nAr duomenis ivesite patys ar nuskaitysite is failo? (T- taip; N - ne, nuskaitysiu is failo): "; cin >> x;
    while (x != "T" && x != "t" && x != "N" && x != "n") {
        cout << "Kazka ne taip ivedete!" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Iveskite T, jei norite patys ivesti duomenis arba N, jei duomenys nuskaitysite is failo: "; cin >> x;
        continue;
    }

    if (x == "T" || x == "t") {
        ivedimas(A, kiek);
    }
    else {
        nuskaitymas(A, kiek);
    }

    isvedimas(A, kiek);

    return 0;
}
