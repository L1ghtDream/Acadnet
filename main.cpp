#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("../soarece.in");
ofstream fout;

int a[14][14], is, js, ib, jb, n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
vector<vector<vector<int>>> solutions;

void citire() {
    fin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            fin >> a[i][j];
    }
    fin >> is >> js >> ib >> jb;
}

void afis(bool final) {
    if (!final) {
        vector<vector<int>> solution;
        for (int i = 1; i <= n; i++) {
            vector<int> line;
            for (int j = 1; j <= m; j++) {
                if (a[i][j] == 1 || a[i][j] == 0)
                    line.push_back(0);
                else
                    line.push_back(a[i][j]);
            }

            solution.push_back(line);
        }

        solutions.push_back(solution);
        return;
    }

    int index = 0;
    int maxxx = 0;
    for (int i = 0; i < solutions.size(); i++) {
        int maxx = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (solutions[i][j][k] > maxx) {
                    maxx = solutions[i][j][k];
                }
            }
        }

        if (maxx > maxxx) {
            maxxx = maxx;
            index = i;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            if (solutions[index][i][j] == 1 || solutions[index][i][j] == 0) {
                fout << 0 << " ";
            } else {
                fout << solutions[index][i][j] - 1 << " ";
            }
        fout << endl;
    }

    for (int i = 1; i <= n; i++) {

    }
}

int valid(int x, int y) {
    if (x > n || x < 1 || y > m || y < 1)
        return 0;
    return !a[x][y];
}

void bktr(int i, int j, int pas) {
    for (int dir = 0; dir <= 3; dir++) {
        int l, c;
        l = i + dy[dir];
        c = j + dx[dir];
        if (valid(l, c) == 1) {
            a[l][c] = pas;
            if (l == ib && c == jb) {
                afis(false);
            } else
                bktr(l, c, pas + 1);
            a[l][c] = 0;
        }
    }
}

int main() {
    fout.open("../soarece.out");
    citire();
    a[is][js] = 1;
    bktr(is, js, 2);
    afis(true);
    fout.close();
    return 0;
}
