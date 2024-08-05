#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        const int m = board.size();
        const int n = board[0].size();

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j) {
                int ones = 0;
                for (int x = max(0, i - 1); x < min(m, i + 2); ++x)
                    for (int y = max(0, j - 1); y < min(n, j + 2); ++y)
                        ones += board[x][y] & 1;
                if (board[i][j] == 1 && (ones == 3 || ones == 4))
                    board[i][j] |= 0b10;
                if (board[i][j] == 0 && ones == 3)
                    board[i][j] |= 0b10;
            }

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                board[i][j] >>= 1;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> board = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 1, 1},
        {0, 0, 0}
    };

    cout << "Initial Board:" << endl;
    for (const auto& row : board) {
        for (int cell : row)
            cout << cell << " ";
        cout << endl;
    }

    solution.gameOfLife(board);

    cout << "Next Generation Board:" << endl;
    for (const auto& row : board) {
        for (int cell : row)
            cout << cell << " ";
        cout << endl;
    }

    return 0;
}
