#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
#include <vector>
#include <fstream>
#include "Rusiavimas.h"

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

void vidurkis(vector<Studentas>& A, int x) {
    if (A[x].n > 0) {
        A[x].vidurkis = double(A[x].sum) / double(A[x].n) * 0.40 + double(A[x].egz) * 0.60;
    }
    else {
        A[x].vidurkis = double(A[x].egz) * 0.60;
    }
}

void mediana(vector<Studentas>& A, int x) {

    int t;
    int p = A[x].n;
    A[x].paz.push_back(1);

    for (int i = p; i > 0; i--) {
        A[x].paz[i] = A[x].paz[i - 1];
    }

    A[x].paz[0] = A[x].egz;
    p++;

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p - i - 1; j++) {
            if (A[x].paz[j] < A[x].paz[j + 1]) {
                t = A[x].paz[j];
                A[x].paz[j] = A[x].paz[j + 1];
                A[x].paz[j + 1] = t;
            }
        }
    }

    if (p == 0) {
        A[x].mediana = A[x].paz[p];
    }
    else if (p % 2 == 0) {
        A[x].mediana = (A[x].paz[p / 2] + A[x].paz[p / 2 - 1]) / 2.0;
    }
    else {
        A[x].mediana = A[x].paz[p / 2];
    }
}

void pazymiai(vector<Studentas>& A, int x) {

    A[x].sum = 0;

    int rPaz = rand() % 10 + 1;
    A[x].egz = rPaz;

    int rKiek = rand() % 15 + 1;
    A[x].n = rKiek;

    for (int i = 0; i < A[x].n; i++) {
        A[x].paz.push_back(1);
        int rPaz = rand() % 10 + 1;
        A[x].paz[i] = rPaz;
        A[x].sum += rPaz;
    }
}

void studentai(vector<Studentas>& A, int kiek) {

    A.push_back(Studentas());

    for (int x = 0; x < kiek; x++) {

        A.push_back(Studentas());

        A[x].vardas = "Vardas" + to_string(x + 1);
        A[x].pavarde = "Pavarde" + to_string(x + 1);

        pazymiai(A, x);
    }
}

void failai(vector<Studentas>& A, int& kiek) {
    ofstream fout;

    kiek = 1000;
    srand((unsigned int)time(0));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < i; j++) {
            kiek = kiek * 10;
        }
        studentai(A, kiek);
        fout.open(to_string(kiek)+".txt");
        
        cout << kiek << " sugeneruota; ";

        int ilgvardas = 0, ilgpavarde = 0;
        for (int x = 1; x < kiek; x++) {
            if (A[x].vardas.length() > A[x - 1].vardas.length() && A[x].vardas.length() > ilgvardas) {
                ilgvardas = A[x].vardas.length();
            }
            else if (A[x - 1].vardas.length() > ilgvardas) {
                ilgvardas = A[x - 1].vardas.length();
            }

            if (A[x].pavarde.length() > A[x - 1].pavarde.length() && A[x].pavarde.length() > ilgpavarde) {
                ilgpavarde = A[x].pavarde.length();
            }
            else if (A[x - 1].pavarde.length() > ilgpavarde) {
                ilgpavarde = A[x - 1].pavarde.length();
            }
        }

        if (kiek == 1) {
            ilgvardas = A[0].vardas.length();
            ilgpavarde = A[0].pavarde.length();
        }

        fout << left << setw(ilgvardas + 5) << "Vardas" << left << setw(ilgpavarde + 5) << "Pavarde" << left << setw(15) << "Galutinis(Vid.)" << " / " << left << setw(15) << "Galutinis(Med.)" << endl;
        fout << setfill('-') << setw(ilgvardas + ilgpavarde + 43) << '-' << endl;
        for (int x = 0; x < kiek; x++) {
            vidurkis(A, x);
            mediana(A, x);
            fout << setfill(' ') << left << setw(ilgvardas + 5) << A[x].vardas << left << setw(ilgpavarde + 5) << A[x].pavarde << left << setw(18) << fixed << setprecision(2) << A[x].vidurkis << left << setw(15) << fixed << setprecision(2) << A[x].mediana << endl;
        }
        fout.close();


        vidurkiu_rusiavimas(A, kiek);

        fout.open(to_string(kiek) + "nevykeliai.txt");
        fout << left << setw(ilgvardas + 5) << "Vardas" << left << setw(ilgpavarde + 5) << "Pavarde" << left << setw(15) << "Galutinis(Vid.)" << " / " << left << setw(15) << "Galutinis(Med.)" << endl;
        fout << setfill('-') << setw(ilgvardas + ilgpavarde + 43) << '-' << endl;
        for (int x = 0; x < kiek; x++) {
            if (A[x].vidurkis < 5) {
                fout << setfill(' ') << left << setw(ilgvardas + 5) << A[x].vardas << left << setw(ilgpavarde + 5) << A[x].pavarde << left << setw(18) << fixed << setprecision(2) << A[x].vidurkis << left << setw(15) << fixed << setprecision(2) << A[x].mediana << endl; 
            }
            
        }
        fout.close();

        fout.open(to_string(kiek) + "protinguoliai.txt");
        fout << left << setw(ilgvardas + 5) << "Vardas" << left << setw(ilgpavarde + 5) << "Pavarde" << left << setw(15) << "Galutinis(Vid.)" << " / " << left << setw(15) << "Galutinis(Med.)" << endl;
        fout << setfill('-') << setw(ilgvardas + ilgpavarde + 43) << '-' << endl;
        for (int x = 0; x < kiek; x++) {
            if (A[x].vidurkis >= 5) {
                fout << setfill(' ') << left << setw(ilgvardas + 5) << A[x].vardas << left << setw(ilgpavarde + 5) << A[x].pavarde << left << setw(18) << fixed << setprecision(2) << A[x].vidurkis << left << setw(15) << fixed << setprecision(2) << A[x].mediana << endl;
            }
        }
        fout.close();

        cout << kiek << " surusiuota; ";
    }
}