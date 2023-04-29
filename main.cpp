#include <cstdio>

using namespace std;

const int BUFSIZE = 160;

char buf[BUFSIZE];
int pbeg, len;
FILE *fin = stdin;
FILE *fout = stdout;

int f() {
    static int state = 0;
    int ch;
    int i;
    int lastspc;

    switch (state) {
        case 0:
            while (1) {
                // AVETI VOIE SA MODIFICATI DE AICI
                ch = fgetc(fin);

                if (ch == EOF || ch == '\n') {
                    break;
                } else {
                    buf[len++] = (char) ch;
                }

                if (ch == ' ') {
                    if (len > 81) {
                        for (i = 0; i < lastspc; i++) {
                            fputc(buf[i], fout);
                        }
                        fputc('\n', fout);
                        int index = 0;
                        for (int j = lastspc; j <= len; j++, index++) {
                            buf[index] = buf[j];
                        }
                        for (int j = index; j <= len; j++) {
                            buf[j] = ' ';
                        }
                        len -= lastspc;
                    }
                    lastspc = len;
                }
            }
            state = 1;
            break;
        case 1:        // NU AVETI VOIE SA STERGETI
        case 2:        // NU AVETI VOIE SA STERGETI
        case 4:        // NU AVETI VOIE SA STERGETI
        case 3:        // NU AVETI VOIE SA STERGETI
            break;
    }
    return state;
    // AVETI VOIE SA MODIFICATI PANA AICI
}

int main() {
    while (!f());

    return 0;
}
