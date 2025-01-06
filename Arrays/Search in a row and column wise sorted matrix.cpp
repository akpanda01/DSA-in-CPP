//Search in a row and column wise sorted matrix


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();        // Number of rows
        int n = matrix[0].size();     // Number of columns
        int row = 0, col = n - 1;     // Start at the top-right corner

        while (row < m && col >= 0) {
            int current = matrix[row][col];

            if (current == target) {
                return true;          // Found the target
            } else if (current > target) {
                col--;                // Move left
            } else {
                row++;                // Move down
            }
        }
        
        return false;                 // Target not found
    }
};
