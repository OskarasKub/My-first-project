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
};

int main() {
    studentas A;
    int n, p, sum = 0, t;

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

    cout << "Kiek turi namu darbu pazymiu?: "; cin >> n;
    while (cin.fail() || n < 0) {
        cout << "Pazymiu kiekis turi buti teigiamas SKAICIUS!" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Kiek turi namu darbu pazymiu?: "; cin >> n;
        continue;
    }

    for (int i = 0; i < n; i++) {
        cout << "Iveskite " << i + 1 << "-aji pazymi: ";
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

    cout << "\n\n" << left << setw(A.vardas.length() + 5) << "Vardas" << left << setw(A.pavarde.length() + 5) << "Pavarde" << left << setw(15) << "Galutinis(Vid.)" << endl;
    cout << setfill('-') << setw(A.vardas.length() + A.pavarde.length() + 43) << '-' << endl;
    cout << setfill(' ') << left << setw(A.vardas.length() + 5) << A.vardas << left << setw(A.pavarde.length() + 5) << A.pavarde << left << setw(18) << fixed << setprecision(2) << A.pazymys <<  endl;
    return 0;
}
