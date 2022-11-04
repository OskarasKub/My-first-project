#include "mylib.h"
#include "Timer.h"
#include "Funkcijos.h"

int main() {

    Timer t;
    double laik1 = 0, laik2 = 0;

    srand(time(NULL));
    int kiek = 0;
    vector<Studentas> sar, protinguoliai, nevykeliai;
    list<Studentas> sar2, protinguoliai2, nevykeliai2;

    int dydziai[3] = {1000, 10000, 100000};
    string filename;
    string s;

    printf("%-47s %-20s %-0s \n", "", "Vector laikas (s.)", "List laikas (s.)");
    cout << string(87, '-') << "\n";
    for (int i = 0; i < 3; i++) {
        s = std::to_string(dydziai[i]);
        filename = s + ".txt";
        t.reset();
        duomenys_vector(filename, sar, kiek);
        laik1 = t.elapsed();

        t.reset();
        duomenys_list(filename, sar2, kiek);
        laik2 = t.elapsed();
        printf("%-47s %-20.8lf %-20.8lf\n", (s + " studentu failo nuskaitymas").c_str(), laik1, laik2);

        t.reset();
        sort(sar.begin(), sar.end(), compare);
        dvigrupes_vector(sar, nevykeliai, protinguoliai);
        laik1 = t.elapsed();

        t.reset();
        sar2.sort(compare);
        dvigrupes_list(sar2, nevykeliai2, protinguoliai2);
        laik2 = t.elapsed();
        printf("%-47s %-20.8lf %-20.8lf\n", (s + " studentu failo rusiavimas i kategorijas").c_str(), laik1, laik2);
    }


    return 0;
}
