#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::left;
using std::setw;
using std::setfill;
using std::fixed;
using std::setprecision;

struct Studentas {
    string vardas;
    string pavarde;
    double pazymys;
    int n=0;
    int paz[10];
    int egz;
    double mediana;
    int sum=0;
};

int main() {
    
    struct Studentas A[99];
    int p, t, kiek = 0;

    cout << "\nIveskite studentu kieki: "; cin >> kiek;
    while (cin.fail() || kiek < 1) {
        cout << "Studentu kiekis turi buti SKAICIUS didesnis uz nuli!" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Iveskite studentu kieki: "; cin >> kiek;
        continue;
    }

    for (int x = 0; x < kiek; x++) {

        cout << "\n" << x+1 << "-asis studentas." << endl;
        cout << "Iveskite studento varda: "; cin >> A[x].vardas;
        cout << "Iveskite studento pavarde: "; cin >> A[x].pavarde;

        string gen;
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

            string zin;
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

                for (int i = 0; i < A[x].n; i++) {
                    cout << "Iveskite " << i + 1 << "-aji pazymi: ";
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
                cout << "\nVeskite namu darbu pazymius. Jei pazymiu nebera iveskite 0.\n" << endl;
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
                    }
                }
            }
        }
        else {
            srand((unsigned int)time(0));

            int rPaz = rand() % 10 + 1;
            cout << "\nSugeneruotas egzamino pazymys: " << rPaz << endl;
            A[x].egz = rPaz;

            int rKiek = rand() % 10 + 0;
            cout << "\nSugeneruotas namu darbu pazymiu kiekis: " << rKiek << endl;
            A[x].n = rKiek;

            for (int i = 0; i < A[x].n; i++) {
                int rPaz = rand() % 10 + 1;
                cout << "\nSugeneruotas " << i + 1 << "-asis pazymys: " << rPaz << endl;
                A[x].paz[i] = rPaz;
                A[x].sum += rPaz;
            }
        }

        string pas;
        cout << "\nJei norite pazymiu vidurkio spauskite ""V"", jei norite medianos spauskite ""M"": "; cin >> pas;
        while (pas != "V" && pas != "v" && pas != "M" && pas != "m") {
            cout << "Kazka ne taip ivedete!" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Iveskite V, jei norite, kad butu apskaiciuotas vidurkis arba M, jei norite medianos: "; cin >> pas;
            continue;
        }

        p = A[x].n;

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

        if (pas == "V" || pas == "v") {
            if (A[x].n > 0) {
                A[x].pazymys = double(A[x].sum) / double(A[x].n) * 0.40 + double(A[x].egz) * 0.60;
            }
            else {
                A[x].pazymys = double(A[x].egz) * 0.60;
            }

            cout << "\n\n" << left << setw(A[x].vardas.length() + 5) << "Vardas" << left << setw(A[x].pavarde.length() + 5) << "Pavarde" << left << setw(15) << "Galutinis(Vid.)" << endl;
            cout << setfill('-') << setw(A[x].vardas.length() + A[x].pavarde.length() + 25) << '-' << endl;
            cout << setfill(' ') << left << setw(A[x].vardas.length() + 5) << A[x].vardas << left << setw(A[x].pavarde.length() + 5) << A[x].pavarde << left << setw(18) << fixed << setprecision(2) << A[x].pazymys << endl;
        }
        else {
            if (p == 0) {
                A[x].mediana = A[x].paz[p];
            }
            else if (p % 2 == 0) {
                A[x].mediana = (A[x].paz[p / 2] + A[x].paz[p / 2 - 1]) / 2.0;
            }
            else {
                A[x].mediana = A[x].paz[p / 2];
            }

            cout << "\n\n" << left << setw(A[x].vardas.length() + 5) << "Vardas" << left << setw(A[x].pavarde.length() + 5) << "Pavarde" << left << setw(15) << "Galutinis(Med.)" << endl;
            cout << setfill('-') << setw(A[x].vardas.length() + A[x].pavarde.length() + 25) << '-' << endl;
            cout << setfill(' ') << left << setw(A[x].vardas.length() + 5) << A[x].vardas << left << setw(A[x].pavarde.length() + 5) << A[x].pavarde << left << setw(15) << fixed << setprecision(2) << A[x].mediana << endl;
        }
    }
    return 0;
}
