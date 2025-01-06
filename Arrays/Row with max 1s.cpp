//Row with max 1s


class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        int n = arr.size(); // Number of rows
        int m = arr[0].size(); // Number of columns
        
        int max1sRow = -1; // Index of the row with max 1s
        int j = m - 1;     // Start at the top-right corner
        
        for (int i = 0; i < n; i++) {
            // Move left while there are 1s in the current row
            while (j >= 0 && arr[i][j] == 1) {
                max1sRow = i;
                j--;
            }
        }
        
        return max1sRow;
    }
};
