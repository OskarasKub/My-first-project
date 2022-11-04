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
void duomenys_vector(string filename, vector<Studentas>& sar, int& kiek);
void duomenys_list(string filename, list<Studentas>& sar, int& kiek);
void dvigrupes_vector(vector<Studentas>& sar, vector<Studentas>& nevykeliai, vector<Studentas>& protinguoliai);
void dvigrupes_list(list<Studentas>& sar, list<Studentas>& nevykeliai, list<Studentas>& protinguoliai);
bool compare(Studentas a, Studentas b);