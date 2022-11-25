#include "mylib.h"
#include "Funkcijos.h"
#include "Timer.h"

double avg(vector<int>& arr, int n) {
    if (n > 0) {
        return std::accumulate(arr.begin(), arr.end(), 0.0) / (double)n;
    }
    return 0;
}

double vidurkis(double temp, double egz) {
    return 0.4 * temp + 0.6 * (double)egz;
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

void sugeneravimas(vector<Studentas>& A, int x) {
    srand((unsigned int)time(0));

    int rPaz = rand() % 10 + 1;
    cout << "\nSugeneruotas egzamino pazymys: " << rPaz << endl;
    A[x].egz = rPaz;

    int rKiek = rand() % 15 + 1;
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

void ivedimas(vector<Studentas>& A, int& kiek) {

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
            double temp;
            temp = avg(A[x].paz, A[x].n);
            A[x].vidurkis = vidurkis(temp, A[x].egz);
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

void nuskaitymas(vector<Studentas>& A, int& kiek) {

    using std::ifstream;

    string zodziai;
    ifstream fin;
    double temp;
    kiek = 0;

    try {
        fin.open("kursiokai.txt");
        if (!fin.is_open()) {
            throw 0;
        }

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

        fin.close();
        
        for (int x = 0; x < kiek; x++) {
            temp = avg(A[x].paz, A[x].n);
            A[x].vidurkis = vidurkis(temp, A[x].egz);
            mediana(A, x);
        }
    }
    catch (...) {
        cout << "\nToks failas neegzistuoja!";
    }
}

void pazymiai(vector<Studentas>& A, int x) {

    A[x].sum = 0;

    int rPaz = rand() % 10 + 1;
    A[x].egz = rPaz;

    int rKiek = 5;
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
    ofstream fout, fout2;
    Timer t;
    double temp, laik = 0;


    srand((unsigned int)time(0));
    for (int i = 0; i < 3; i++) {
        kiek = 1000;
        for (int j = 0; j < i; j++) {
            kiek = kiek * 10;
        }
        studentai(A, kiek);
        fout.open(to_string(kiek) + ".txt");

        cout << "\n" << kiek << " studentu irasu sugeneravimo laikas: " << t.elapsed() << endl;
        laik = t.elapsed();
        t.reset();

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

        fout << left << setw(ilgvardas + 5) << "Vardas" << left << setw(ilgpavarde + 5) << "Pavarde" << left << setw(5) << "ND1" << left << setw(5) << "ND2" << left << setw(5) << "ND3" << left << setw(5) << "ND4" << left << setw(5) << "ND5" << left << setw(5) << "EGZ" << endl;
        fout << "\n";
        for (int x = 0; x < kiek; x++) {
            temp = avg(A[x].paz, A[x].n);
            A[x].vidurkis = vidurkis(temp, A[x].egz);
            fout << setfill(' ') << left << setw(ilgvardas + 5) << A[x].vardas << left << setw(ilgpavarde + 5) << A[x].pavarde;
            for (int j = 0; j < A[x].n; j++) {
                fout << left << setw(5) << A[x].paz[j];
            }
            fout << left << setw(5) << A[x].egz << endl;
        }
        fout.close();

        cout << kiek << " studentu surasymo i faila laikas: " << t.elapsed() << endl;
        laik += t.elapsed();
        t.reset();

        sort(A.begin(), A.end(), compare);

        cout << kiek << " studentu surusiavimo laikas: " << t.elapsed() << endl;
        laik += t.elapsed();
        t.reset();

        fout.open(to_string(kiek) + "nevykeliai.txt");
        fout << left << setw(ilgvardas + 5) << "Vardas" << left << setw(ilgpavarde + 5) << "Pavarde" << left << setw(15) << "Galutinis(Vid.)" << endl;
        fout << "\n";
        fout2.open(to_string(kiek) + "protinguoliai.txt");
        fout2 << left << setw(ilgvardas + 5) << "Vardas" << left << setw(ilgpavarde + 5) << "Pavarde" << left << setw(15) << "Galutinis(Vid.)" << endl;
        fout2 << "\n";
        for (int x = 0; x < kiek; x++) {
            if (A[x].vidurkis < 5 && A[x].vidurkis > 0) {
                fout << setfill(' ') << left << setw(ilgvardas + 5) << A[x].vardas << left << setw(ilgpavarde + 5) << A[x].pavarde << left << setw(18) << fixed << setprecision(2) << A[x].vidurkis << endl;
            }
            else if (A[x].vidurkis >= 5){
                fout2 << setfill(' ') << left << setw(ilgvardas + 5) << A[x].vardas << left << setw(ilgpavarde + 5) << A[x].pavarde << left << setw(18) << fixed << setprecision(2) << A[x].vidurkis << endl;
            }
        }
        fout.close();
        fout2.close();

        cout << kiek << " studentu padalinimo i dvi grupes ir surasymo i failus laikas: " << t.elapsed() << endl;
        laik += t.elapsed();
        t.reset();
        cout << "\nDarbo su " << kiek << " irasu testo laikas: " << laik << endl;

    }
}

void duomenys_vector(string filename, vector<Studentas>& A, int& kiek) {
    try {
        std::ifstream fin(filename);
        if (!fin.fail()) {
            int sk;
            double temp2;
            string line;
            string temp, pirmaEil;
            int kiekNd = -3;
            std::getline(fin >> std::ws, pirmaEil);
            stringstream iss(pirmaEil);
            while (iss >> temp)
            {
                kiekNd++;
            }
            while (std::getline(fin >> std::ws, line)) {
                Studentas s;
                stringstream iss(line);
                iss >> s.vardas;
                iss >> s.pavarde;
                for (int i = 0; i < kiekNd; i++) {
                    iss >> sk;
                    s.paz.resize(s.paz.size() + 1);
                }
                iss >> sk;
                s.egz = sk;
                temp2 = avg(s.paz, kiekNd);
                s.vidurkis = vidurkis(temp2, s.egz);
                A.resize(A.size() + 1);
            }
        }
        else {
            throw std::runtime_error(filename);
        }
        kiek = A.size();
    }
    catch (std::exception& e) {
        cout << "\nIvyko problema nuskaitant faila: " << e.what() << "\n";
        std::exit(0);
    }
}

void duomenys_list(string filename, list<Studentas>& A, int& kiek) {
    try {
        std::ifstream fin(filename);
        if (!fin.fail()) {
            int sk;
            double temp2;
            string line;
            string temp, pirmaEil;
            int kiekNd = -3;
            std::getline(fin >> std::ws, pirmaEil);
            stringstream iss(pirmaEil);
            while (iss >> temp)
            {
                kiekNd++;
            }
            while (std::getline(fin >> std::ws, line)) {
                Studentas s;
                stringstream iss(line);
                iss >> s.vardas;
                iss >> s.pavarde;
                for (int i = 0; i < kiekNd; i++) {
                    iss >> sk;
                    s.paz.resize(s.paz.size() + 1);
                }
                iss >> sk;
                s.egz = sk;
                temp2 = avg(s.paz, kiekNd);
                s.vidurkis = vidurkis(temp2, s.egz);
                A.resize(A.size() + 1 );
            }
        }
        else {
            throw std::runtime_error(filename);
        }
        kiek = A.size();
    }
    catch (std::exception& e) {
        cout << "Ivyko problema nuskaitant faila: " << e.what() << "\n";
        std::exit(0);
    }
}

void dvigrupes_vector(vector<Studentas>& A, vector<Studentas>& nevykeliai, vector<Studentas>& protinguoliai) {
    for (auto& s : A) {
        if (s.vidurkis < 5.00) nevykeliai.resize(nevykeliai.size() + 1);
        else protinguoliai.resize(protinguoliai.size() + 1); 
    }
    A.clear();
}

void dvigrupes_list(list<Studentas>& A, list<Studentas>& nevykeliai, list<Studentas>& protinguoliai) {
    for (auto& s : A) {
        if (s.vidurkis < 5.00) nevykeliai.resize(nevykeliai.size() + 1);
        else protinguoliai.resize(protinguoliai.size() + 1);
    }
    A.clear();
}

void vienagrupe_vector(vector<Studentas>& A, vector<Studentas>& nevykeliai) {
    auto x = A.begin();
    while (x != A.end()) {
        if ((*x).vidurkis < 5.00) {
            nevykeliai.push_back(*x);
            x++;
        }
        else {
            break;
        }
    }
    A.erase(A.begin(), x);
}

void vienagrupe_list(list<Studentas>& A, list<Studentas>& nevykeliai) {
    auto x = A.begin();
    while (x != A.end()) {
        if ((*x).vidurkis < 5.00) {
            nevykeliai.push_back(*x);
            x++;
        }
        else {
            break;
        }
    }
    A.erase(A.begin(), x);
}

void optimizacija(vector<Studentas>& A, vector <Studentas>& nevykeliai) {
    stable_partition(A.begin(), A.end(), [](const Studentas& s) { return s.vidurkis < 5.00; });
    auto x = find_if(A.begin(), A.end(), [](const Studentas& s) { return s.vidurkis >= 5.00; });
    copy(A.begin(), x, back_inserter(nevykeliai));
    A.erase(A.begin(), x);
}

void printToFile(string filename, vector<Studentas>& A, int ndSkaicius) {
    stringstream buffer;
    ofstream out(filename);
    buffer << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << "Galutinis(Vid.)" << "\n";
    for (int i = 0; i < A.size(); i++) {
        buffer << left << setw(15) << A[i].vardas << setw(15) << A[i].pavarde << fixed
            << setprecision(2) << A[i].vidurkis << "\n";
    }
    out << buffer.str();
    buffer.clear();
    out.close();
}


bool compare(Studentas a, Studentas b) {
    return a.vidurkis < b.vidurkis;
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

    if (kiek == 1) {
        ilgvardas = A[0].vardas.length();
        ilgpavarde = A[0].pavarde.length();
    }

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

void testavimas(vector<Studentas> A, list<Studentas> B, int kiek) {
    Timer t;
    double laik1 = 0, laik2 = 0;
    srand(time(NULL));

    string filename;
    string s;
    int dydziai[5] = { 1000, 10000, 100000, 1000000, 10000000};

    vector<Studentas> protinguoliai, nevykeliai, A2, A3;
    list<Studentas> protinguoliai2, nevykeliai2, B2;


    printf("%-47s %-20s %-0s \n", "", "Vector laikas (s.)", "List laikas (s.)");
    cout << string(87, '-') << "\n";
    for (int i = 0; i < 3; i++) {
        s = std::to_string(dydziai[i]);
        filename = s + ".txt";

        t.reset();
        duomenys_vector(filename, A, kiek);
        laik1 = t.elapsed();

        t.reset();
        duomenys_list(filename, B, kiek);
        laik2 = t.elapsed();

        A2 = A;
        A3 = A;
        B2 = B;


        printf("%-47s %-20.8lf %-0lf\n", (s + " studentu failo nuskaitymas").c_str(), laik1, laik2);

        t.reset();
        sort(A.begin(), A.end(), compare);
        dvigrupes_vector(A, nevykeliai, protinguoliai);
        laik1 = t.elapsed();
        nevykeliai.clear();

        t.reset();
        B.sort(compare);
        dvigrupes_list(B, nevykeliai2, protinguoliai2);
        laik2 = t.elapsed();
        nevykeliai.clear();
         
        printf("%-47s %-20.8lf %-20.8lf\n", (s + " studentu failo rusiavimas i kategorijas").c_str(), laik1, laik2);

        t.reset();
        sort(A2.begin(), A2.end(), compare);
        vienagrupe_vector(A2, nevykeliai);
        laik1 = t.elapsed();
        nevykeliai.clear();

        t.reset();
        B2.sort(compare);
        vienagrupe_list(B2, nevykeliai2);
        laik2 = t.elapsed();
        nevykeliai.clear();

        printf("%-47s %-20.8lf %-20.8lf\n", (s + " studentu dalinimas su vienu konteineriu").c_str(), laik1, laik2);

        t.reset();
        optimizacija(A3, nevykeliai);
        laik1 = t.elapsed();
        nevykeliai.clear();
        printf("%-47s %-20.8lf\n", (s + " irasu optimizuotas dalijimas i grupes").c_str(), laik1);

        cout << string(87, '-') << "\n";
    }

}
