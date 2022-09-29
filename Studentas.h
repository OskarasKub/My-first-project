#include <iostream>
#include <vector>
using std::vector;
using std::string;

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
