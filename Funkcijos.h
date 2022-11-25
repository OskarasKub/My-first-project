#include "mylib.h"

struct Studentas {
    string vardas; //Studento vardas
    string pavarde; //Studento pavarde
    int n = 0; //Namu darbu kiekis
    vector<int> paz; //Namu darbu pazymiai
    int egz; //Egzamino pazymys
    double vidurkis; //Pazymiu vidurkis
    double mediana; //Pazymiu mediana
    int sum = 0; //Pazymiu suma
};

double avg(vector<int>& arr, int n);
double vidurkis(double temp, double egz);
void mediana(vector<Studentas>& A, int x);
void sugeneravimas(vector<Studentas>& A, int x);
void ivedimas(vector<Studentas>& A, int& kiek);
unsigned int kiekPazymiu(std::string const& str);
void nuskaitymas(vector<Studentas>& A, int& kiek);
void pazymiai(vector<Studentas>& A, int x);
void studentai(vector<Studentas>& A, int kiek);
void failai(vector<Studentas>& A, int& kiek);
void duomenys_vector(string filename, vector<Studentas>& A, int& kiek);
void duomenys_list(string filename, list<Studentas>& A, int& kiek);
void dvigrupes_vector(vector<Studentas>& A, vector<Studentas>& nevykeliai, vector<Studentas>& protinguoliai);
void dvigrupes_list(list<Studentas>& A, list<Studentas>& nevykeliai, list<Studentas>& protinguoliai);
void vienagrupe_vector(vector<Studentas>& A, vector<Studentas>& nevykeliai);
void vienagrupe_list(list<Studentas>& A, list<Studentas>& nevykeliai);
void optimizacija(vector<Studentas>& A, vector <Studentas>& nevykeliai);
bool compare(Studentas a, Studentas b);
void isvedimas(vector<Studentas> A, int kiek);
void testavimas(vector<Studentas> A, list<Studentas> B, int kiek);
//void failai(int& kiek);