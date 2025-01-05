#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    // Function to check if it's safe to place a queen at position (i, j)
    bool isSafe(int i, int j, vector<vector<string> >& vec, int n) {
        // Check the column for other queens
        for (int row = 0; row < i; ++row) {
            if (vec[row][j] == "Q") {
                return false;
            }
        }

        // Check the top-left diagonal
        for (int row = i - 1, col = j - 1; row >= 0 && col >= 0; --row, --col) {
            if (vec[row][col] == "Q") {
                return false;
            }
        }

        // Check the top-right diagonal
        for (int row = i - 1, col = j + 1; row >= 0 && col < n; --row, ++col) {
            if (vec[row][col] == "Q") {
                return false;
            }
        }

        return true;  // No conflicts found
    }

    // Function for backtracking to place queens row by row
    bool backtracking(int i, vector<vector<string> >& vec, int n) {
        // Base case: If all queens have been placed successfully
        if (i == n) {
            return true;
        }

        // Try placing a queen in each column of the current row
        for (int j = 0; j < n; ++j) {
            if (isSafe(i, j, vec, n)) {
                vec[i][j] = "Q";  // Place the queen

                // Recursively try to place queens in the next row
                if (backtracking(i + 1, vec, n)) {
                    return true;  // Solution found
                }

                // Backtrack: Remove the queen if no solution was found
                vec[i][j] = ".";
            }
        }

        return false;  // No valid placement found in this row
    }

    // Main function to solve N-Queens
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > vec(n, vector<string>(n, "."));
        backtracking(0, vec, n);  // Start placing queens from the first row
        return vec;
    }
};

int main() {
    Solution sol;
    int n;
    cin >> n;

    // Solve the N-Queens problem
    vector<vector<string> > vec = sol.solveNQueens(n);

    // Print the solution
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << vec[i][j] << " ";  // Print queens on the same row in a single line
        }
        cout << endl;  // Move to the next row after printing one row
    }

    return 0;
}
