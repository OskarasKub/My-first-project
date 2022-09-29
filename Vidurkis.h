#include <iostream>
#include <vector>

void vidurkis(vector<Studentas>& A, int x) {
    if (A[x].n > 0) {
        A[x].vidurkis = double(A[x].sum) / double(A[x].n) * 0.40 + double(A[x].egz) * 0.60;
    }
    else {
        A[x].vidurkis = double(A[x].egz) * 0.60;
    }
}
