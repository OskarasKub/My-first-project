#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>

using namespace std;

struct studentas {
    string vardas;
    string pavarde;
    double pazymys;
    int paz[10];
    int egz;
    double mediana;
};

int main() {
    studentas A;
    int n = 0, p, sum = 0, t;

    cout << "Iveskite studento varda: "; cin >> A.vardas;
    cout << "\nIveskite studento pavarde: "; cin >> A.pavarde;

    string gen;
    cout << "\nAr norite patys ivesti studento pazymius? (T-suvesti, N-sugeneruoti atsitiktinai): "; cin >> gen;
    while (gen != "T" && gen != "N") {
        cout << "Kazka ne taip ivedete!" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Iveskite T, jei norite patys ivesti studento pazymius arba N, jei norite, kad jie butu sugeneruoti atsitiktinai: "; cin >> gen;
        continue;
    }

    if (gen == "T") {
        cout << "\nIveskite egzamino pazymi: "; cin >> A.egz;
        while (cin.fail() || A.egz < 1 || A.egz > 10) {
            cout << "Egzamino pazymys turi buti SKAICIUS nuo 1 iki 10!" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Iveskite egzamino pazymi: "; cin >> A.egz;
            continue;
        }

        string zin;
        cout << "\nAr zinote namu darbu pazymiu skaiciu? (T-taip, N-ne): "; cin >> zin;
        while (zin != "T" && zin != "N") {
            cout << "Kazka ne taip ivedete!" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Iveskite T, jei zinote namu darbu skaiciu arba N, jei nezinote: "; cin >> zin;
            continue;
        }

        if (zin == "T") {
            cout << "\nKiek turi namu darbu pazymiu?: "; cin >> n;
            while (cin.fail() || n < 0) {
                cout << "Pazymiu kiekis turi buti teigiamas SKAICIUS!" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                cout << "Kiek turi namu darbu pazymiu?: "; cin >> n;
                continue;
            }

            for (int i = 0; i < n; i++) {
                cout << "\nIveskite " << i + 1 << "-aji pazymi: ";
                cin >> A.paz[i];
                while (cin.fail() || A.paz[i] < 1 || A.paz[i] > 10) {
                    cout << "Pazymys turi buti SKAICIUS nuo 1 iki 10!" << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Iveskite " << i + 1 << "-aji pazymi: "; cin >> A.paz[i];
                    continue;
                }
                sum += A.paz[i];
            }
        }
        else {
            int i = 0;
            cout << "\nVeskite namu darbu pazymius. Jei pazymiu nebera iveskite 0.\n" << endl;
            while (A.paz[i] != 0) {
                cout << "Iveskite " << i + 1 << "-aji namu darbu pazymi: ";
                cin >> A.paz[i];
                while (cin.fail() || A.paz[i] < 0 || A.paz[i] > 10) {
                    cout << "Pazymys turi buti SKAICIUS nuo 1 iki 10!" << endl;
                    cin.clear();
                    cin.ignore(256, '\n');
                    cout << "Iveskite " << i + 1 << "-aji namu darbu pazymi: "; cin >> A.paz[i];
                    continue;
                }
                if (A.paz[i] != 0) {
                    sum += A.paz[i];
                    i++;
                    n++;
                }
            }
        }
    }
    else {
        srand(time(0));

        int rPaz = rand() % 10 + 1;
        cout << "\nSugeneruotas egzamino pazymys: " << rPaz << endl;
        A.egz = rPaz;

        int rKiek = rand() % 20 + 0;
        cout << "\nSugeneruotas namu darbu pazymiu kiekis: " << rKiek << endl;
        n = rKiek;

        for (int i = 0; i < n; i++) {
            int rPaz = rand() % 10 + 1;
            cout << "\nSugeneruotas " << i + 1 << "-asis pazymys: " << rPaz << endl;
            A.paz[i] = rPaz;
            sum += rPaz;
        }
    }

    string pas;
    cout << "\nJei norite pazymiu vidurkio spauskite ""V"", jei norite medianos spauskite ""M"": "; cin >> pas;
    while (pas != "V" && pas != "M") {
        cout << "Kazka ne taip ivedete!" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Iveskite V, jei norite, kad butu apskaiciuotas vidurkis arba M, jei norite medianos: "; cin >> pas;
        continue;
    }

    p = n;

    for (int i = p; i > 0; i--) {
        A.paz[i] = A.paz[i - 1];
    }

    A.paz[0] = A.egz;
    p++;

    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p - i - 1; j++) {
            if (A.paz[j] < A.paz[j + 1]) {
                t = A.paz[j];
                A.paz[j] = A.paz[j + 1];
                A.paz[j + 1] = t;
            }
        }
    }

    if (pas == "V") {
        if (n > 0) {
            A.pazymys = double(sum) / double(n) * 0.40 + double(A.egz) * 0.60;
        }
        else {
            A.pazymys = double(A.egz) * 0.60;
        }

        cout << "\n\n" << left << setw(A.vardas.length() + 5) << "Vardas" << left << setw(A.pavarde.length() + 5) << "Pavarde" << left << setw(15) << "Galutinis(Vid.)" << endl;
        cout << setfill('-') << setw(A.vardas.length() + A.pavarde.length() + 25) << '-' << endl;
        cout << setfill(' ') << left << setw(A.vardas.length() + 5) << A.vardas << left << setw(A.pavarde.length() + 5) << A.pavarde << left << setw(18) << fixed << setprecision(2) << A.pazymys << endl;
    }
    else {
        if (p == 0) {
            A.mediana = A.paz[p];
        }
        else if (p % 2 == 0) {
            A.mediana = (A.paz[p / 2] + A.paz[p / 2 - 1]) / 2.0;
        }
        else {
            A.mediana = A.paz[p / 2];
        }

        cout << "\n\n" << left << setw(A.vardas.length() + 5) << "Vardas" << left << setw(A.pavarde.length() + 5) << "Pavarde" << left << setw(15) << "Galutinis(Med.)" << endl;
        cout << setfill('-') << setw(A.vardas.length() + A.pavarde.length() + 25) << '-' << endl;
        cout << setfill(' ') << left << setw(A.vardas.length() + 5) << A.vardas << left << setw(A.pavarde.length() + 5) << A.pavarde << left << setw(15) << fixed << setprecision(2) << A.mediana << endl;
    }

    return 0;
}
