#include <iostream>
#include <vector>

void mediana(vector<Studentas>& A, int x){

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
