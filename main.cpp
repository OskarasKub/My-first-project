#include <iostream>
#include <string>
#include <iomanip>

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
    cout << "Iveskite studento pavarde: "; cin >> A.pavarde;

    cout << "Iveskite egzamino pazymi: "; cin >> A.egz;
    while (cin.fail() || A.egz < 1 || A.egz > 10) {
        cout << "Egzamino pazymys turi buti SKAICIUS nuo 1 iki 10!" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Iveskite egzamino pazymi: "; cin >> A.egz;
        continue;
    }

    int i = 0;
    cout << "Veskite namu darbu pazymius. Jei pazymiu nebera iveskite 0." << endl;
    while (A.paz[i] != 0) {
        cout << "Iveskikte " << i + 1 << "-aji namu darbu pazymi: ";
        cin >> A.paz[i];
        while (cin.fail() || A.paz[i] < 0 || A.paz[i] > 10) {
            cout << "Pazymys turi buti SKAICIUS nuo 1 iki 10!" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Iveskikte " << i + 1 << "-aji namu darbu pazymi: "; cin >> A.paz[i];
            continue;
        }
        if (A.paz[i] != 0) {
            sum += A.paz[i];
            i++;
            n++;
        }
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

    if (n > 0) {
        A.pazymys = double(sum) / double(n) * 0.40 + double(A.egz) * 0.60;
    }
    else {
        A.pazymys = double(A.egz) * 0.60;
    }

    if (p == 0) {
        A.mediana = A.paz[p];
    }
    else if (p % 2 == 0) {
        A.mediana = (A.paz[p / 2] + A.paz[p / 2 - 1]) / 2.0;
    }
    else {
        A.mediana = A.paz[p / 2];
    }

    cout << "\n\n" << left << setw(A.vardas.length() + 5) << "Vardas" << left << setw(A.pavarde.length() + 5) << "Pavarde" << left << setw(15) << "Galutinis(Vid.)" << left << setw(3) << " / " << left << setw(15) << "Galutinis(Med.)" << endl;
    cout << setfill('-') << setw(A.vardas.length() + A.pavarde.length() + 43) << '-' << endl;
    cout << setfill(' ') << left << setw(A.vardas.length() + 5) << A.vardas << left << setw(A.pavarde.length() + 5) << A.pavarde << left << setw(18) << fixed << setprecision(2) << A.pazymys << left << setw(15) << fixed << setprecision(2) << A.mediana << endl;
    return 0;
}
