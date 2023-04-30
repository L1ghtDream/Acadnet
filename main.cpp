#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

void print_spiral(int m, int n, vector<vector<int> >&matrix)
{
    int i;
    int x = 0, y = 0;

    while (m > 0 && n > 0) {
        if (m == 1) {
            for (i = 0; i < n; i++) {
                printf("%d ",matrix[x][y++]);
            }
            break;
        }
        else if (n == 1){
            for (i = 0; i < m; i++){
                printf("%d ", matrix[x++][y]);
            }
            break;
        }

        //go right
        for (i = 0; i < n; i++) {
            printf("%d ", matrix[x][y++]);
        }

        //go down
        for (i = 0; i < m; i++) {
            printf("%d ", matrix[x--][y]);
        }

        //go left
        for (i = 0; i < n; i++) {
            printf("%d ", matrix[x][y--]);
        }

        //go up
        for (i = 0; i < m; i++) {
            printf("%d ", matrix[x++][y]);
        }

        x++;
        y++;
        m--;
        n--;
    }
}

int main()
{
    int n, m;

    scanf("%d%d", &m, &n);

    int cnt = 1;
    int i, j;
    vector<vector<int> > matrix = vector<vector<int> >(m, vector<int>(n, 0));

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++){
            cout<<cnt++ << " ";
        }
        cout<<endl;
    }

    //print_spiral(m, n, matrix);

    return 0;
}

