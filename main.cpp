#include <iostream>
#include <algorithm>

using namespace std;
struct Cutie {
    int index;
    int nr_jucarii;
};
struct Mutare {
    int sursa;
    int destinatie;
    int jucarii;
};

bool rule(Cutie a, Cutie b) {
    return a.nr_jucarii < b.nr_jucarii;
}

int main() {
    int nr_cutii;
    cin >> nr_cutii;
    if (nr_cutii == 0 || nr_cutii == 1) {
        cout << "0" << endl;
    } else {
        struct Cutie cutii[1005];
        int medie_jucarii = 0;
        for (int i = 0; i < nr_cutii; i++) {
            cin >> cutii[i].nr_jucarii;
            medie_jucarii += cutii[i].nr_jucarii;
            cutii[i].index = i;
        }
        medie_jucarii /= nr_cutii;
        cout << "Medie: " << medie_jucarii << endl;

        struct Mutare mutari[1005];
        //int count = 0;
        //sort(cutii, cutii + nr_cutii, rule);

        //for (int i = 0; i < nr_cutii; i++) {
        //    cout<<cutii[i].nr_jucarii<<" ";
        //}

        //cout<<endl;

        bool moved = true;
        int index = 0;

        while (moved) {
            moved = false;
            int max = 0;
            int maxIndex = -1;

            int min = 100000;
            int minIndex = -1;

            for (int i = 0; i < nr_cutii; i++) {
                if (cutii[i].nr_jucarii > max) {
                    maxIndex = i;
                    max = cutii[i].nr_jucarii;
                }
            }

            for (int i = 0; i < nr_cutii; i++) {
                if (cutii[i].nr_jucarii < min) {
                    minIndex = i;
                    min = cutii[i].nr_jucarii;
                }
            }

            if (maxIndex != -1 && minIndex != -1 && max != medie_jucarii && min != medie_jucarii) {
                moved = true;

                Mutare mutare;
                mutare.sursa = maxIndex + 1;
                mutare.destinatie = minIndex + 1;
                mutare.jucarii = medie_jucarii - min;
                mutari[index++] = mutare;

                cutii[minIndex].nr_jucarii = medie_jucarii;
                cutii[maxIndex].nr_jucarii = max - medie_jucarii + min;
            }
        }


        cout << index << endl;
        for (int i = 0; i < index; i++) {
            cout << mutari[i].sursa << " " << mutari[i].jucarii << " " << mutari[i].destinatie << endl;
        }
    }
}