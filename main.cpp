#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
#include <vector>
#include <fstream>
#include <sstream>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::left;
using std::setw;
using std::setfill;
using std::fixed;
using std::setprecision;
using std::vector;

void sugeneravimas(vector<Studentas>& A, int x) {
    srand((unsigned int)time(0));

    int rPaz = rand() % 10 + 1;
    cout << "\nSugeneruotas egzamino pazymys: " << rPaz << endl;
    A[x].egz = rPaz;

    int rKiek = rand() % 10 + 0;
    cout << "\nSugeneruotas namu darbu pazymiu kiekis: " << rKiek << endl;
    A[x].n = rKiek;

    for (int i = 0; i < A[x].n; i++) {
        A[x].paz.push_back(1);
        int rPaz = rand() % 10 + 1;
        cout << "Sugeneruotas " << i + 1 << "-asis pazymys: " << rPaz << endl;
        A[x].paz[i] = rPaz;
        A[x].sum += rPaz;
    }
}

void ivedimas(vector<Studentas> &A, int &kiek) {

    cout << "\nIveskite studentu kieki: "; cin >> kiek;
    while (cin.fail() || kiek < 1) {
        cout << "Studentu kiekis turi buti SKAICIUS didesnis uz nuli!" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Iveskite studentu kieki: "; cin >> kiek;
        continue;
    }

    for (int x = 0; x < kiek; x++) {

        A.push_back(Studentas());

        cout << "\n" << x + 1 << "-asis studentas." << endl;
        cout << "Iveskite studento varda: "; cin >> A[x].vardas;
        cout << "Iveskite studento pavarde: "; cin >> A[x].pavarde;

        string gen; //Ar ives pazymius pats ar juos sugeneruos
        cout << "\nAr norite patys ivesti studento pazymius? (T-suvesti, N-sugeneruoti atsitiktinai): "; cin >> gen;
        while (gen != "T" && gen != "t" && gen != "N" && gen != "n") {
            cout << "Kazka ne taip ivedete!" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Iveskite T, jei norite patys ivesti studento pazymius arba N, jei norite, kad jie butu sugeneruoti atsitiktinai: "; cin >> gen;
            continue;
        }

        if (gen == "T" || gen == "t") {
            cout << "\nIveskite egzamino pazymi: "; cin >> A[x].egz;
            while (cin.fail() || A[x].egz < 1 || A[x].egz > 10) {
                cout << "Egzamino pazymys turi buti skaicius nuo 1 iki 10!" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Iveskite egzamino pazymi: "; cin >> A[x].egz;
                continue;
            }

            string zin; //Ar namu darbu skaicius zinomas ar ne
            cout << "\nAr zinote namu darbu pazymiu skaiciu? (T-taip, N-ne): "; cin >> zin;
            while (zin != "T" && zin != "t" && zin != "N" && zin != "n") {
                cout << "Kazka ne taip ivedete!" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Iveskite T, jei zinote namu darbu skaiciu arba N, jei nezinote: "; cin >> zin;
                continue;
            }

            if (zin == "T" || zin == "t") {
                cout << "\nKiek turi namu darbu pazymiu?: "; cin >> A[x].n;
                while (cin.fail() || A[x].n < 0) {
                    cout << "Pazymiu kiekis turi buti teigiamas SKAICIUS!" << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Kiek turi namu darbu pazymiu?: "; cin >> A[x].n;
                    continue;
                }

                A[x].paz.push_back(A[x].n);

                for (int i = 0; i < A[x].n; i++) {
                    cout << "Iveskite " << i + 1 << "-aji pazymi: ";
                    A[x].paz.push_back(1);
                    cin >> A[x].paz[i];
                    while (cin.fail() || A[x].paz[i] < 1 || A[x].paz[i] > 10) {
                        cout << "Pazymys turi buti SKAICIUS nuo 1 iki 10!" << endl;
                        cin.clear();
                        cin.ignore(256, '\n');
                        cout << "Iveskite " << i + 1 << "-aji pazymi: "; cin >> A[x].paz[i];
                        continue;
                    }
                    A[x].sum += A[x].paz[i];
                }
            }
            else {
                int i = 0;
                A[x].paz.push_back(1);
                cout << "\nVeskite namu darbu pazymius. Jei pazymiu nebera iveskite 0." << endl;
                while (A[x].paz[i] != 0) {
                    cout << "Iveskite " << i + 1 << "-aji namu darbu pazymi: ";
                    cin >> A[x].paz[i];
                    while (cin.fail() || A[x].paz[i] < 0 || A[x].paz[i] > 10) {
                        cout << "Pazymys turi buti SKAICIUS nuo 1 iki 10!" << endl;
                        cin.clear();
                        cin.ignore(256, '\n');
                        cout << "Iveskite " << i + 1 << "-aji namu darbu pazymi: "; cin >> A[x].paz[i];
                        continue;
                    }
                    if (A[x].paz[i] != 0) {
                        A[x].sum += A[x].paz[i];
                        i++;
                        A[x].n++;
                        A[x].paz.push_back(1);
                    }
                }
            }
        }
        else {
            sugeneravimas(A, x);
        }

        string pas; //Ar pasirinks vidurki ar mediana
        cout << "\nJei norite pazymiu vidurkio spauskite ""V"", jei norite medianos spauskite ""M"": "; cin >> pas;
        while (pas != "V" && pas != "v" && pas != "M" && pas != "m") {
            cout << "Kazka ne taip ivedete!" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Iveskite V, jei norite, kad butu apskaiciuotas vidurkis arba M, jei norite medianos: "; cin >> pas;
            continue;
        }

        if (pas == "V" || pas == "v") {
            A[x].mediana = 0;
            vidurkis(A, x);
        }
        else {
            A[x].vidurkis = 0;
            mediana(A, x);
        }
    }
}

unsigned int kiekPazymiu(std::string const& str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream), std::istream_iterator<std::string>());
}

void nuskaitymas(vector<Studentas> &A, int &kiek) {

    using std::ifstream;

    string duom;
    string zodziai;
    ifstream fin;
    kiek = 0;

    fin.open("kursiokai.txt");

    getline(fin >> std::ws, zodziai);
    int n = kiekPazymiu(zodziai) - 3;

    A.push_back(Studentas());
    A[kiek].paz.push_back(n);

    while (!fin.eof()) {
        A.push_back(Studentas());
        A[kiek].n = n;
        fin >> A[kiek].vardas;
        fin >> A[kiek].pavarde;

        for (int i = 0; i < n; i++) {
            A[kiek].paz.push_back(1);
            fin >> A[kiek].paz[i];
            A[kiek].sum += A[kiek].paz[i];
        }
        fin >> A[kiek].egz;
        kiek++;
    }

    for (int x = 0; x < kiek; x++) {
        vidurkis(A, x);
        mediana(A, x);
    }
}

void pavardziu_rusiavimas(vector<Studentas>& A, int kiek) {
    //?????????
}

void isvedimas(vector<Studentas> A, int kiek) {

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

    pavardziu_rusiavimas(A, kiek);

    cout << "\n\n" << left << setw(ilgvardas + 5) << "Vardas" << left << setw(ilgpavarde + 5) << "Pavarde" << left << setw(15) << "Galutinis(Vid.)" << " / " << left << setw(15) << "Galutinis(Med.)" << endl;
    cout << setfill('-') << setw(ilgvardas + ilgpavarde + 43) << '-' << endl;
    for (int x = 0; x < kiek; x++) {
        if (A[x].mediana == 0) {
            cout << setfill(' ') << left << setw(ilgvardas + 5) << A[x].vardas << left << setw(ilgpavarde + 5) << A[x].pavarde << left << setw(18) << fixed << setprecision(2) << A[x].vidurkis << left << setw(15) << fixed << setprecision(2) << " - " << endl;
        }
        else if (A[x].vidurkis == 0) {
            cout << setfill(' ') << left << setw(ilgvardas + 5) << A[x].vardas << left << setw(ilgpavarde + 5) << A[x].pavarde << left << setw(18) << fixed << setprecision(2) << " - " << left << setw(15) << fixed << setprecision(2) << A[x].mediana << endl;
        }
        else
            cout << setfill(' ') << left << setw(ilgvardas + 5) << A[x].vardas << left << setw(ilgpavarde + 5) << A[x].pavarde << left << setw(18) << fixed << setprecision(2) << A[x].vidurkis << left << setw(15) << fixed << setprecision(2) << A[x].mediana << endl;

    }
}

int main() {

    vector<Studentas> A;
    int kiek;

    string fa; //Ar vedimas ranka ar is failo
    cout << "\nAr duomenis ivesite patys? (T- taip; N - ne, nuskaitysiu is failo): "; cin >> fa;
    while (fa != "T" && fa != "t" && fa != "N" && fa != "n") {
        cout << "Kazka ne taip ivedete!" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Iveskite T, jei norite patys ivesti duomenis arba N, jei norite, kad jie butu nuskaityti is failo: "; cin >> fa;
        continue;
    }

    if (fa == "T" || fa == "t") {
        ivedimas(A, kiek);
    }
    else {
        nuskaitymas(A, kiek);
    }

    isvedimas(A, kiek);

    return 0;
}

