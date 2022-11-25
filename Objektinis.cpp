#include "mylib.h"
#include "Funkcijos.h"

int main() {
    
    int kiek = 0;
    vector<Studentas> A;
    list<Studentas> B;
    int x;

    cout << "\nKoki veiksma norite atlikti?";
    
    cout << "\n\nNoriu duomenis ivesti pats arba sugeneruoti. -> 1 ";
    cout << "\nNoriu duomenis nuskaityti is failo. -> 2 ";
    cout << "\nNoriu sugeneruoti 5 studentu failus. -> 3";
    cout << "\nNoriu atlikti konteineriu testavima. -> 4 ";
    cout << "\n\nIveskite atitinkama uzduoties skaiciu: ", cin >> x;

    while (x != 1 && x != 2 && x != 3 && x != 4) {
        cout << "Kazka ne taip ivedete!" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Iveskite skaiciu tos uzduoties, kuria norite atlikti: "; cin >> x;
        continue;
    }

    if (x == 1) {
        cout << "\nPasirinkta duomenis ivesti paciam\\generuoti.";
        cout << "\n";
        ivedimas(A, kiek);
        isvedimas(A, kiek);
    }
    else if (x == 2) {
        cout << "\nPasirinkta duomenis nuskaityti is failo.";
        cout << "\n";
        nuskaitymas(A, kiek);
        isvedimas(A, kiek);
    }
    else if (x == 3) {
        cout << "\nPasirinkta sugeneruoti 5 failus.";
        cout << "\n";
        failai(A, kiek);
    }
    else if (x == 4) {
        cout << "\nPasirinkta atlikti konteineriu testavima.";
        cout << "\n";
        testavimas(A, B, kiek);
    }

    return 0;
}
