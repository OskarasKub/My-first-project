#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include "Studentas.h"
#include "Sugeneravimas.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::ofstream;

void vidurkis(vector<Studentas>& A, int x);
void mediana(vector<Studentas>& A, int x);
void pazymiai(vector<Studentas>& A, int x);
void studentai(vector<Studentas>& A, int kiek);
void failai(vector<Studentas>& A, int& kiek);


int main() {

    vector<Studentas> A;
    int kiek;

    failai(A, kiek);

    return 0;
}
