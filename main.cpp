#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void flood_island(vector <vector < char >> &grid, int r, int c) {
    int nr = grid.size();
    int nc = grid[0].size();

    grid[r][c] = '0';
    if (r - 1 >= 0 && grid[r - 1][c] == '1') flood_island(grid, r - 1, c);
    if (r + 1 < nr && grid[r + 1][c] == '1') flood_island(grid, r + 1, c);
    if (c - 1 >= 0 && grid[r][c - 1] == '1') flood_island(grid, r, c - 1);
    if (c + 1 < nc && grid[r][c + 1] == '1') flood_island(grid, r, c + 1);

    if (r - 1 >= 0 && c - 1 >= 0 && grid[r - 1][c - 1] == '1') flood_island(grid, r - 1, c - 1);
    if (r - 1 >= 0 && c + 1 < nc && grid[r - 1][c + 1] == '1') flood_island(grid, r - 1, c + 1);

    if (r + 1 < nr && c - 1 >= 0 && grid[r + 1][c - 1] == '1') flood_island(grid, r + 1, c - 1);
    if (r + 1 < nr && c + 1 < nc && grid[r + 1][c + 1] == '1') flood_island(grid, r + 1, c + 1);
}

int numIslands(vector < vector < char >> &grid) {
    int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();

    int num_islands = 0;
    for (int r = 0; r < nr; ++r) {
        for (int c = 0; c < nc; ++c) {
            if (grid[r][c] == '1') {
                ++num_islands;
                flood_island(grid, r, c);
            }
        }
    }

    return num_islands;
}

int main(int argc, char *argv[]) {
    int r, c;
    char ch;
    cin >> r >> c;

    vector<vector<char>> earth_sea;

    for (int i = 0; i < r; ++i) {
        vector<char> v;
        for (int j = 0; j < c; ++j) {
            cin >> ch;
            v.push_back(ch);
        }
        earth_sea.push_back(v);
    }

    cout << numIslands(earth_sea) << endl;

    return 0;
}