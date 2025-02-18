//N-Queen Problem

class Solution {
public:
    vector<vector<string>> result; // Stores all valid N-Queens solutions
    
    // Function to check if a queen can be placed at board[row][col]
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // Check vertical column for existing queens
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        // Check upper left diagonal for existing queens
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        // Check upper right diagonal for existing queens
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true; // It is safe to place a queen here
    }
    
    // Recursive function to place queens on the board
    void solve(vector<string>& board, int row, int n) {
        // Base case: If all queens are placed, store the solution
        if (row == n) {
            result.push_back(board);
            return;
        }
        // Try placing a queen in each column of the current row
        for (int col = 0; col < n; col++) {
            // Check if placing a queen at (row, col) is safe
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q'; // Place the queen
                solve(board, row + 1, n); // Recur for next row
                board[row][col] = '.'; // Backtrack: Remove queen
            }
        }
    }
    
    // Main function to solve the N-Queens problem
    vector<vector<string>> solveNQueens(int n) {
        result.clear(); // Clear previous results
        vector<string> board(n, string(n, '.')); // Create an empty N×N board
        solve(board, 0, n); // Start placing queens from row 0
        return result; // Return all valid solutions
    }
};
