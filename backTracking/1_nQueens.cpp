#include <iostream>
#include <vector>

bool isSafe(int** state, int row, int col, int n) {
    for (int i = 0; i < row; i++) {
        if (state[i][col] == 1) {
            return false;
        }
    }

    int r = row;
    int c = col;
    while (row >= 0 && col >= 0) {
        if (state[r][c] == 1) {
            return false;
        }
        r--;
        c--;
    }

    r = row;
    c = col;
    while (row >= 0 && col < n) {
        if (state[r][c] == 1) {
            return false;
        }
        r--;
        c++;
    }

    return true;
}

bool solve(int** state, int x, int n) {
    if (x >= n) {
        return true;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(state, x, col, n)) {
            state[x][col] = 1;

            if (solve(state, x + 1, n)) {
                return true;
            }

            state[x][col] = 0;
        }
    }
    return false;
}

std::vector<std::vector<int>> solveNQueens(int n) {
    std::vector<std::vector<int>> solution = { {0} };

    if (solve(solution, 0, n)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << solution[i][j] << " ";

            }
            std::cout << std::endl;
        }
    }

    return solution;
}

int main(int argc, char const* argv[]) {
    // std::cout << "Enter N : " << std::endl;
    // int n;
    // std::cin >> n;

    // std::vector<std::vector<int>> sol = solveNQueens(n);

    solveNQueens(4);

#if 0
    std::cout << "Solution : " << std::endl;
    for (int i = 0; i < sol.size(); i++) {
        for (int j = 0; j < sol[i].size(); i++) {
            std::cout << sol[i][j] << " ";
        }
        std::cout << std::endl;
    }
#endif

    return 0;
}
