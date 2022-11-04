#include "mylib.h"
#include "Funkcijos.h"

double avg(vector<int>& arr, int n) {
    if (n > 0) {
        return std::accumulate(arr.begin(), arr.end(), 0.0) / (double)n;
    }
    return 0;
}

double vidurkis(double temp, double egz) {
    return 0.4 * temp + 0.6 * (double)egz;
}

void duomenys_vector(string filename, vector<Studentas>& sar, int& kiek) {
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
                    s.paz.push_back(sk);
                }
                iss >> sk;
                s.egz = sk;
                temp2 = avg(s.paz, kiekNd);
                s.vidurkis = vidurkis(temp2, s.egz);
                sar.push_back(s);
            }
        }
        else {
            throw std::runtime_error(filename);
        }
        kiek = sar.size();
    }
    catch (std::exception& e) {
        cout << "Ivyko problema nuskaitant faila: " << e.what() << "\n";
        std::exit(0);
    }
}

void duomenys_list(string filename, list<Studentas>& sar, int& kiek) {
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
                    s.paz.push_back(sk);
                }
                iss >> sk;
                s.egz = sk;
                temp2 = avg(s.paz, kiekNd);
                s.vidurkis = vidurkis(temp2, s.egz);
                sar.push_back(s);
            }
        }
        else {
            throw std::runtime_error(filename);
        }
        kiek = sar.size();
    }
    catch (std::exception& e) {
        cout << "Ivyko problema nuskaitant faila: " << e.what() << "\n";
        std::exit(0);
    }
}

void dvigrupes_vector(vector<Studentas>& sar, vector<Studentas>& nevykeliai, vector<Studentas>& protinguoliai) {
    for (auto& s : sar) {
        if (s.vidurkis < 5.00) nevykeliai.push_back(s);
        else protinguoliai.push_back(s);
    }
    sar.clear();
}

void dvigrupes_list(list<Studentas>& sar, list<Studentas>& nevykeliai, list<Studentas>& protinguoliai) {
    for (auto& s : sar) {
        if (s.vidurkis < 5.00) nevykeliai.push_back(s);
        else protinguoliai.push_back(s);
    }
    sar.clear();
}

bool compare(Studentas a, Studentas b) {
    return a.vardas < b.vardas;
}
